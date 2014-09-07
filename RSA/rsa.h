#ifndef RSA_H
#define RSA_H

#include <QMainWindow>
#include<stdlib.h>  //para los numeros aleatorios para el algoritmo primalidad
#include<time.h>
#include<QDebug>
#include <math.h>
#include <QMessageBox>

using namespace std;

namespace Ui {
class RSA;
}

class RSA : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit RSA(QWidget *parent = 0);
    int LehmanPeralta(unsigned long long num);   //algoritmo para el Test de primalidad de un entero
    unsigned long long expoRapido(unsigned long long base,unsigned long long exp,unsigned long long modulo);//exponenciacion
    unsigned long long expoRapido2(unsigned long long base,unsigned long long exp,unsigned long long modulo);  //modular
    void EuclidesExtendido();  //para saber si  d es primo con φ(n) y calcular e
    void codiNumerica(); //codificación numérica del texto
    void codiNumerica2();
    int getpos(char letra);  //posicion de la letra en el alfabeto
    void cifrar();
    ~RSA();
    
private slots:
    void on_ejecutar_clicked();

    void on_ejecutar_2_clicked();

private:
    Ui::RSA *ui;
    QString texto,p,q,d,salida,cifrado,nAleatorios,fi;
    unsigned long long n,*a,*resA,*textNumerico;  //array donde guardamos los numeros aleatorios y las operaciones con ellos
    long long mcd,e;  //maximo comun divisor y numero e
    int bloques,base;  //numero de caracteres para codificar
    string alfabeto;
};

#endif // RSA_H
