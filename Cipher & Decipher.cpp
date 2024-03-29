// File     : CS112_A2_T2_S28_20230315_20230256_20230213.cpp
// Purpose  : Cipher and decipher programs

// Author 1 : Mohamed Ahmed Kotb and he did simplest cipher [5]
// ID 1     : 20230315

// Author 2 : Omar Sayed Soliman Ibrahim and he did Polybius Square cipher [6]
// ID 2     : 20230256

// Author 3 : Abdelrahman Mohamed Ahmed El-Gaml and he did Vignere cipher [3]
// ID 3     : 20230213

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
using namespace std;
void main_menu(string& c,string& mes,bool& flag,string& chos_cipher)
{
    flag = false;
    while (true)
    {
        cout << "Welcome to the user...\n"
                "What do you like to do today: \n"
                "1- Cipher a message\n"
                "2- Decipher a message\n"
                "3- End the program\n";
        getline(cin, c);
        if (c != "1"&& c != "2"&& c != "3") {
            cout << "Please enter a valid input....\n";
            continue;
        } else
            break;
    }
    while (!flag) {
        if(c == "1")
        {
            cout << "Enter the message to cipher :\n ";
            getline(cin, mes);
            cout << "Which Cipher do you like to choose?\n"
                    "1- Vignere Cipher\n"
                    "2- Simple Substitution Cipher\n"
                    "3- Polybius Square Cipher\n";
            getline(cin, chos_cipher);
            flag = true;
        }
        else if (c == "2")
        {
            cout << "Enter the message to decipher : ";
            getline(cin, mes);
            cout << "Which Cipher do you like to choose?\n"
                    "1- Simple Substitution Cipher\n";
            getline(cin, chos_cipher);
            flag = true;

        }
        else if (c == "3")
        {
            cout << "Ending the program....\n"
                    "Hava a nice time";
            flag = false;
            exit(0);
        }
        else
        {
            cout << "Please enter a valid input....\n";
            flag = false;
        }
    }
}
string decipher(string inp,int len,string& alp,string& res,string& cip){
    for (int i = 0; i < len; i++) {
        if (isalpha(inp[i])) {
            for (int j = 0; j < 26; ++j) {
                if (tolower(inp[i]) == cip[j]) {
                    res.append(1, alp[j]);
                    break;
                }
            }
        }else {
            res.append(1, inp[i]);
        }
    }
    return res;
}
string encrypt(string& inp,int len, string& cip,string& res,string& alp) {
    for (int i = 0; i < len; i++) {
        if (isalpha(inp[i])) {
            for (int j = 0; j < 26; ++j) {
                if (tolower(inp[i]) == alp[j]) {
                    res.append(1, cip[j]);
                    break;
                }
            }
        }else {
            res.append(1, inp[i]);
        }
    }
    return res;
}
void to_lower(string& key){
   for (int i = 0; i < key.length() ; ++i)
   {
       tolower(key[i]);
   }
}
string to_upper(string& key){
    string res = "";
    for (int i = 0; i < key.length() ; ++i)
    {
        if(isalpha(key[i]))
        {
            char upper_char =toupper(key[i]);
            res += upper_char;
        }
        else
        {
            res += key[i];
        }
    }
    return res;
}
string Adding_key(string& cip,string key){
   int pos;
   for (int i = key.length()-1; i >= 0 ; i-- )
   {
       if(isalpha(key[i])){
           pos = cip.find((key[i]));
           cip.erase(cip.begin()+pos);
       }

   }
   cip.insert(0,key);
   return cip;
}

int main()
{
   string message,key_word,choice,choose_cipher;
   bool flag = false,flag_2= true;
   string choose,result = "";
   string alpha = "abcdefghijklmnopqrstuvwxyz";
   string cipher = "abcdefghijklmnopqrstuvwxyz";
   while (true) {
       main_menu(choice, message, flag, choose_cipher);
       if (choice == "1" && choose_cipher == "3")
       {
           bool flag_1 = true;
           while (flag_1)
           {
               cout<<"Enter number sequences: "<< "\n";
               int key[5];
               for(int x=0;x<5;x++){
                   cin>>key[x];
               }
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               char a[5][5]={0};
               int num=65;
               for(int x=0;x<5;x++){
                   for(int y=0;y<5;y++){
                       if (num ==74) num++;
                       a[x][y]=char(num);
                       num++;
                   }
               }
               for(int c=0; c < message.length(); c++){
                   int colume,row;
                   char sentencechar;

                   if(message[c] == 'J') sentencechar='I';
                   else sentencechar=message[c];

                   for(int x=0;x<5;x++){
                       for(int y=0;y<5;y++){

                           if(toupper(sentencechar)== a[x][y])
                           {row=x;
                               colume=y;}
                       }
                   }
                   if(sentencechar==' ') cout<<' ';
                   else cout<<key[row]<<key[colume];

               }
               cout<<endl;
               cout << "If you want to: \n"
                       "1) Return to the main menu\n"
                       "End the program press any key\n";
               getline(cin ,choose);
               if (choose == "1")
                   flag_1 = false;
               else
               {
                   cout << "Ending the program....\n"
                           "Hava a nice time";
                   return 0;
               }
           }
       }
       else if (choice == "1" && choose_cipher == "2") {
           cout << "Enter the keyword: ";
           getline(cin, key_word);
           to_lower(key_word);
           string Add_key = Adding_key(cipher, key_word);

           string enc = encrypt(message, message.length(), cipher, result, alpha);
           cout << "Encrypted: " << enc << endl;
           while (flag_2)
           {
               string restore;
               cout << "If you want to: \n"
                       "1- Decipher and restore it\n"
                       "2 -Return to the main menu\n "
                       "End the program press any key\n ";
               getline(cin, restore);
               if (restore == "1")
               {
                   string Key;
                   cout << "Please enter the same key to decipher it: ";
                   getline(cin, Key);
                   if (Key == key_word)
                   {
                       string new_res;
                       string recover = decipher(result, message.length(), alpha, new_res, cipher);
                       cout << "Deciphered: " << recover << endl;
                       cout << "If you want to: \n"
                               "1) Return to the main menu\n"
                               "End the program press any key\n";
                       getline(cin ,choose);
                       if (choose == "1")
                           flag_2 = false;
                       else {
                           cout << "Ending the program....\n"
                                   "Hava a nice time";
                           return 0;
                       }
                   } else {
                       cout << "You have entered a false key\n"
                               "Please try again\n";
                       continue;
                   }
               }else if (restore == "2")
                   break;
               else
               {
                   cout << "Ending the program\n"
                        "Hava a nice time.";
                   return 0;
               }
           }
       }
       else if (choice == "2" && choose_cipher == "1")
       {
           bool flag_3 = true;
           while (flag_3){
               cout << "Enter the keyword: ";
               getline(cin, key_word);
               to_lower(key_word);
               string Add_key = Adding_key(cipher, key_word);
               string deci = decipher(message, message.length(), alpha, result, cipher);
               cout << "Deciphered: "<< deci << endl;
               cout << "If you want to: \n"
                       "1) Return to the main menu\n"
                       "End the program press any key\n";
               getline(cin , choose);
               if (choose == "1")
                   flag_3 = false;
               else
               {
                   cout << "Ending the program....\n"
                           "Hava a nice time";
                   return 0;
               }
           }

       }
       else if (choice == "1" && choose_cipher == "1"){
           bool flag_4 = true;
           while (flag_4)
           {
               if (message.length() > 80)
               {
                 cout << "You have entered over 80 characters\n"
                         "Please enter less than that\n";
                 break;
               }
               cout << "Enter the keyword: ";
               string keyword;
               getline(cin , keyword);
               if (key_word.length() > 8)
               {
                   cout << "You have entered over 8 characters\n"
                           "Please enter less than that\n";
                   break;
               }
               string new_key= "";
               for (int j = 0; j < message.length() ; ++j)
               {
                   new_key += keyword[j % keyword.length()];
               }
               message = to_upper(message);
               new_key = to_upper(new_key);
               string result_1 ="";
               for (int k = 0 ; k<message.length();++k){
                   if(isalpha(message[k])){
                       result_1 +=char(65 + ((message[k] + new_key[k]) % 26)) ;
                   }
                   else
                       result_1 += message[k];
               }
               cout << result_1 << endl;
               cout << "If you want to: \n"
                       "1) Return to the main menu\n"
                       "End the program press any key\n";
               getline(cin , choose);
               if (choose == "1")
                   flag_4 = false;
               else
               {
                   cout << "Ending the program....\n"
                           "Hava a nice time";
                   return 0;
               }
           }
       }
   continue;
   }
}