#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>


std::string str;
std::string strInput;
std::ifstream inf("pass.txt");
std::ofstream fout("pass.txt");

int count_line = 0;
bool prof = true;
int povtor = 0;

char buff[62] = {'A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z','0','1','2','3','4','5','6','7','8','9'};

bool check(std::string str) { // проверка на существование записи
    inf.clear();
    inf.seekg(0);
    while (std::getline(inf, strInput)) 
    { 
        if (strInput == str) 
        {
            povtor++;
            return true;
        }
         
    }
 
    
    return false;

}

void BruteForce(int str_long) {

    for (;;) {
        
        for (int i = 0; i < str_long; i++) 
        {
            str += buff[rand() % 62 + 0];       
        }

        if (!check(str))
        {
        fout << str << std::endl;
        count_line++;
        }
        else if (check(str))
        {
            continue;
        }
        
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
    BruteForce(4);
    

}



