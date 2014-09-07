#include "rsa.h"
#include "ui_rsa.h"

RSA::RSA(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RSA)
{
    ui->setupUi(this);
}

RSA::~RSA()
{
    delete ui;
}

void RSA::on_ejecutar_clicked()
{
    QMessageBox msgBox;  //ventanas de informacion
    int res;
    base=26;
    alfabeto ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";  //usado para codificar el texto de entrada a int

    //recoger datos de entrada
    texto = ui->textow->toPlainText();
    texto = texto.toUpper(); //a mayusculas
    texto.replace(" ", ""); //quitar espacios en blanco    
    p = ui->pw->text();
    q = ui->qW->text();
    d = ui->dw->text();    
    nAleatorios = ui->nAleatoriosw->text();

    //comprobar que p y q son primos con el algoritmo lehman Peralta

    if ((res=LehmanPeralta(p.toLongLong()) == 0)){
        msgBox.information(this,"RECUERDE","El numero p tiene que ser un numero primo.");
        msgBox.exec();
        ui->salidaw->clear();
    }
    else if((res=LehmanPeralta(q.toLongLong())) == 0){
        msgBox.information(this,"RECUERDE","El numero q tiene que ser un numero primo.");
        msgBox.exec();
        ui->salidaw->clear();
    }
    else{

        //CALCULAMOS FI 0(n)=(p-1)(q-1)
        fi.append(QString::number( (p.toLongLong()-1)* (q.toLongLong()-1)));
        ui->fiw->setText(fi);

        //CALCULAMOS N
        n=p.toLongLong()*q.toLongLong();



        //CALCULAMOS MCD Y e
        EuclidesExtendido();


        //codificacion numerica del texto
        codiNumerica();


        //CIFRAR EL TEXTO
        cifrar();



    }

}




void RSA::on_ejecutar_2_clicked()  //salir del programa
{
    close();
}


int RSA::LehmanPeralta(unsigned long long num) {   //algoritmo para el Test de primalidad de un entero
    unsigned long long aux;
    aux=(num-1)/2;

    a = new unsigned long long[nAleatorios.toInt()];
    resA = new unsigned long long[nAleatorios.toInt()];
    srand(time(NULL));  //semilla con la hora del sistema

    ui->salidaw->append("\n**************************\nEXPONENCIACION RAPIDA\n**************************\nNUMERO: "+QString::number(num)+"\n");
    //creamos los numeros aleatorios y los guardamos en a
    for(int i =0;i<nAleatorios.toInt();i++){
            a[i]=1+rand()%(num-1); //numero aleatorio entre 1-p
    }


    //Para cada i calcular a[i](num-1)/2 (mod num)
    for(int i =0;i<nAleatorios.toInt();i++){        
        resA[i] = expoRapido(a[i],aux,num); //usamos exponenciacion rapida binaria
         resA[i] = resA[i]%num;
    }


    //mostrar traza
    ui->salidaw->append("i\ta\t\t\ta[i](p-1)/2 (mod p)\n----------------------------------------------------------------------------------------------------------------------------------------------------------");
    for(int i =0;i<nAleatorios.toInt();i++){
         ui->salidaw->append(QString::number(i)+"\t"+QString::number((unsigned long long)(a[i]))+"\t\t\t"+QString::number((unsigned long long)(resA[i]))+"\n");
    }


    //saber si es primo o no
    for(int i =0;i<nAleatorios.toInt();i++){
        if(resA[i] != (num-1) && resA[i] != 1){
            ui->salidaw->append("\n**************************************************\nEL NUMERO: "+QString::number(num)+" NO ES UN NUMERO PRIMO.\n******************************************\n");
            return 0;  //el numero es compuesto
        }
    }
    ui->salidaw->append("\n**************************************************\nEL NUMERO: "+QString::number(num)+" ES UN NUMERO PRIMO.\n**************************************************\n");
    return 1;  //el numero es primo





}


unsigned long long RSA::expoRapido(unsigned long long base,unsigned long long exp,unsigned long long modulo)  //binaria
{

    unsigned long long yx = 1;
    QString binario;
    binario = QString::number(exp,2);  //calculamos numero exponente en binario


    unsigned long long *tabla=new unsigned long long[binario.length()];  //tabla para guardar operaciones exponenciacion rapida

    //MOSTRAR EN PANTALLA LA TRAZA DE EXPONENCIACION RAPIDA
    qDebug()<<"\n******************************";
    qDebug()<<"TRAZA DE EXPONENCIACION RAPIDA";
    qDebug()<<"******************************\n";
    qDebug()<<"BASE: "<<base<<" EXPONENTE: "<<exp<<"BINARIO: "<<binario<<"\nTABLA: \n";
    tabla[0]=base;
    qDebug()<<tabla[0];

    for(int i=1;i<binario.length();i++){  //generamos la tabla
        tabla[i] = (unsigned long long)(pow(tabla[i-1],2))%modulo;
        qDebug()<<tabla[i];
    }

    for(int i=(binario.length()-1),j=0;i>=0;i--,j++) {  //calculamos yx
        if(binario[i] == '1') {
            yx= (yx)*tabla[j];
        }

    }
    yx=yx%modulo;

    //MOSTRAR EN PANTALLA LA TRAZA DE EXPONENCIACION RAPIDA
    qDebug()<<"RESULTADO DE MULTIPLICAR LA TABLA, SOLO LOS BIT CON UNO, CON EL MODULO "<<modulo<<": "
           <<QString::number(yx)<<endl;

    return yx;

}

unsigned long long RSA::expoRapido2(unsigned long long base,unsigned long long exp,unsigned long long modulo)  //modular
{

  unsigned long long res = 1,alp,m;
  m=exp;  //valor secreto
  alp = base%modulo;  //alpha
  //MOSTRAR EN PANTALLA LA TRAZA DE EXPONENCIACION RAPIDA
  qDebug()<<"\nTRAZA DE EXPONENCIACION RAPIDA\n";
  qDebug()<<"------------------------------\n";
  qDebug()<<"BASE: "<<base<<" EXPONENTE: "<<exp<<"\n";
  qDebug()<<"i\t\t"<<"BASE\t"<<"m\t"<<"res";
  for (int i = 1;m>0;i++){
    if ((m%2)!=0){  //si es impar
      res = (res*alp)%modulo;
      m=m-1;
    }
    alp = (alp*alp)%modulo;  //si es par
    qDebug()<<i<<"\t"<<"\t"<<alp<<"\t"<< m<<"\t"<<res;
    m = m/2;


  }

  return res;
}


void RSA::EuclidesExtendido(){
    long long x0,x1,z0,z1,aux,div,resto,v,gx;

    //INICIALIZAR:
    x0=fi.toLongLong();
    x1=d.toLongLong();
    gx=x0;
    //SI x0 ES MENOR A x1 LES DAMOS LA VUELTA
    if(x0<x1){
        aux=x0;
        x0=x1;
        x1=aux;
    }
    z0=0;z1=1;
    v=1;

    //MOSTRAMOS TRAZA
    ui->salidaw->append("\n**********************************\nALGORITMO EUCLIDES EXTENDIDO\n**********************************");
    ui->salidaw->append("i\tXi\t\t\tZi\n---------------------------------------------------------------------------------------\n");
    ui->salidaw->append("-1 \t\t\t\t0\n");
    ui->salidaw->append(QString::number(0)+"\t"+QString::number(x0)+"\t\t\t"+QString::number(v)+"\n");
    for(int i =1;resto != 0; i++){
        div=x0/x1;
        resto=x0%x1;
        x0=x1;
        x1=resto;

        if(resto != 0){
            v=( (-1*div)*z1)+z0;
            z0=z1; z1=v;
        }
    ui->salidaw->append(QString::number(i)+"\t"+QString::number(x0)+"\t\t\t"+QString::number(v)+"\n");
    }
    mcd=x0;
    if (v<0){
        v=gx+v;
    }
    e=v;
    if(mcd==1){
        ui->salidaw->append("\nNUMERO e: "+QString::number(e)+"\n\n");
        ui->ew->setText(QString::number(e));
    }

}


//codificación numérica del texto

void RSA::codiNumerica2()
{
    int cont=0,cont2=0;
    long long suma=0,aux;
    QByteArray ba = texto.toLatin1();  //array de bytes

    bloques = log(n)/log(base); //bloques a separar el texto log en base 26 con respecto a n
    textNumerico = new unsigned long long[texto.size()/bloques]; //donde guardamos la codificacion numerica del texto


    for(int i=0;i<texto.size();i++){
        for(int j=(bloques);j>0;j--){
            aux = ((int(ba[cont]-'A')%base));
            suma += pow(base,j)*aux;
            cont++;
        }
        textNumerico[cont2] = suma;
        suma=0;
        i=cont;
        cont2++;
    }

    for(int i=0;i<(texto.size()/bloques);i++){
        ui->salidaw->append(QString::number(textNumerico[i]));
    }

}


//codificación numérica del texto

void RSA::codiNumerica()
{

    int cont=0,cont2=0;
    long long suma=0,aux;
    string text = texto.toStdString();

    bloques = log(n)/log(base); //bloques a separar el texto log en base 26 con respecto a n
    textNumerico = new unsigned long long[(texto.size()/bloques)]; //donde guardamos la codificacion numerica del texto

    for(int i=0;i<(texto.size());i++){
        for(int j=(bloques-1);j>=0;j--){
            aux=getpos(text[cont]);  //posicion letra en el alfabeto
            suma = suma+(pow(base,j)*aux);  //formula 0*26^3+1*26^2+2*26+3
            cont++;
        }
        textNumerico[cont2] = suma; //guardamos cada grupo de caracteres en textNumerico
        suma=0;
        i=cont;
        cont2++;
    }
    ui->salidaw->append("TAMAÑO BLOQUE: "+QString::number(bloques)+"\nCADA BLOQUE DEL TEXTO A DECIMAL:\n");
    for(int i=0;i<(texto.size()/bloques);i++){
      ui->salidaw->append(QString::number(textNumerico[i]));
    }

}

int RSA::getpos(char letra)  //posicion de la letra en el alfabeto
{
    for(int i = 0;i<alfabeto.length();i++){
        if(alfabeto[i]==letra){
            return i;
        }
    }
}


void RSA::cifrar()  //cifrar texto
{
    QString bloqueTexto;
    for(int i = 0;i<(texto.size()/bloques);i++){
        qDebug()<<"\n\n*******************************************\nEXPONENCIACION RAPIDA PARA CIFRAR EL TEXTO: \n*******************************************\n";
        cifrado.append(QString::number(expoRapido2(textNumerico[i],e,n))+ "\t");  //exponenciacion rapida modular
        bloqueTexto.append(QString::number(textNumerico[i])+"\t");
        //MOSTRAR EN SALIDA
        ui->salidaw->append("\n\nTEXTO EN BLOQUE DECIMAL:\t"+bloqueTexto+"\nTEXTO EN BLOQUE CIFRADO:\t"+cifrado+"\n\n");
        ui->cifradow->setText(cifrado);
        ui->cifradow->show();
    }
}




















