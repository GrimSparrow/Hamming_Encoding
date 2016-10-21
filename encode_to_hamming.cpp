#include <QString>
#include <hamming_encoding.h>
#include <QVector>
QString Encode_to_Hamming(QString text, int blockSize){
   QVector<QString> myVector;
   QString result;
   //приведение строки символов к строке битов
   for(int i = 0; i < text.size(); i++){
       result += "0" + QString("%1").arg(text[i].unicode(),0,2);
   }
   //пересчет длины строки в зависимости от длины блока
   int newLenght;
   newLenght = ((result.length() / blockSize) + 1) * blockSize;

   for(int i = result.length(); i < newLenght; i++){
       result += "*";
   }

   myVector.resize(newLenght/blockSize);

   int k = 0;
   //разбиение строки бит на блоки
   for(int j = 0; j < (newLenght/blockSize); j++){
       while(k < (j+1) * blockSize)
       {
           myVector[j] += result[k];
           k++;
       }
   }
   return result;
}
