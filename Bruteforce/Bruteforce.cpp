#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>


char buff[62] = {'A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z','0','1','2','3','4','5','6','7','8','9'};
void BruteForce(int str_long) {

    int count_line = 0;
    bool prof = true;
    int povtor = 0;
    std::string str;
    std::string strInput;
    std::ifstream inf("pass.txt");
    std::ofstream fout("pass.txt");
    for (;;) {
        
        
        for (int i = 0; i < str_long; i++) {
            str += buff[rand() % 62 + 0];       
        }
       

        
        while (getline(inf, strInput)) {
            std::cout << "проверяю " << strInput << " с " << str << std::endl;
            if (strInput == str) {
                //строка совпала
                prof = false;
                povtor++;
                break;
            }
            //system("pause");
        }

        if (prof == true) {           
            fout << str << std::endl;
            count_line++;
            
            
            }
        else{
            prof = true;
            continue;
            
       }
       prof = true;
       
       
        
        std::cout << "Слово записано: " << str << "\nКол-во слов: " << count_line << "\nКол-во повторившихся: " << povtor << "\n";
        str.clear();
     system("cls");
        
        if (GetAsyncKeyState(VK_F1)) {
            fout.close();
            inf.close();
            break;
        }

    }

    
}

int main()
{
    
    srand(time(0));
    setlocale(LC_ALL, "RUS");
    BruteForce(10);
}


