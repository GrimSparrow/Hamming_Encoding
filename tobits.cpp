#include <QString>
#include <QVector>
QString ToBits(QString text, int blockSize){
   QString result;
   QVector<QString> myVector;
   int t = 0;
   //приведение строки символов к строке битов
   for(int i = 0; i < text.size(); i++){
       t = text[i].unicode();
       if(t<128&&t>=64)
           result+="0"+QString("%1").arg(t,0,2);
       else if(t<64)
           result+="00"+QString("%1").arg(t,0,2);
       else
           result+=QString("%1").arg(t,0,2);
   }
    //переопределение длины строки в зависимости от длины блока
   int newLenght;

   if((result.length() % blockSize)!=0)
      newLenght = ((result.length() / blockSize) + 1) * blockSize;
   else
       newLenght = result.length();
   for(int i = result.length(); i < newLenght; i++){
          result += "*";
      }

    myVector.resize(newLenght/blockSize);

    //разбиение строки бит на блоки
    int k = 0;

    for(int j = 0; j < (newLenght/blockSize); j++){
          while(k < (j+1) * blockSize)
          {
              myVector[j] += result[k];
              k++;
          }
      }

    //добавление контрольных бит

    for(int i = 0; i < myVector.size(); i++){
        for(int j = 0;j<=blockSize; j = j*2){
            if(j == 0) {
                myVector[i].insert(j,"#");
                j++;
            }
            else
                myVector[i].insert(j-1,"#");
        }
    }
int count = 0;
    for(int i = 0; i < myVector.size(); i++){
        for(int j = 0;j<myVector[i].size(); j = j*2){
            if(j == 0) {
                for (int k = 1; k <myVector[i].size();k++){
                    if(myVector[i].at(k) == '1') count++;
                }
                if (count % 2 == 0) myVector[i][j] = '0';
                else myVector[i][j] = '1';
                j++;
                count = 0;
            }
            else{
                for (int k = j; k <myVector[i].size();k++){
                    if(myVector[i].at(k) == '1') count++;
                }
                if (count % 2 == 0) myVector[i][j-1] = '0';
                else myVector[i][j-1] = '1';
                count = 0;
            }
        }
        }
    return result;

    }


