#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include <array>
#include <unistd.h>
using namespace std;

char alpha[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int exist(char x,string k){

int k_si=k.size();

int exist=0;
   for(int i=0; i<k_si; i++){
      if(x==k[i]){exist=1; break;}
   }

   return exist;
}

int index_num(char str){
string  al = "abcdefghijklmnopqrstuvwxyz"; 
int index = 0;
for(int i=0; i<26; i++){
   if(al[i]==str){break;}
   else{index++;}
}
return index;
}

int index_num2(char str,string al){
int index = 0;
for(int i=0; i<26; i++){
   if(al[i]==str){break;}
   else{index++;}
}
return index;
}

string cipher55(string str,string keyword){
string cipher;
for(int i=0; i<str.size(); i++){
int index = (index_num(str[i]));
cipher.push_back(keyword[index]);
}
return cipher;
}

string decipher55(string str,string keyword){
   string decipher;
   for(int i=0; i<str.size(); i++){
int index = (index_num2(str[i],keyword));
decipher.push_back(keyword[index]);
}
return decipher;
}

string keyword_alpha(string keyword){
for (int i = 0; i<26; i++){
if(exist(alpha[i],keyword)==1){continue;}
else{keyword.push_back(alpha[i]);}
}
return keyword;
}

int main5(){

string str, cipher,decipher,keyword;
int choose;
/*
transform(str.begin(), str.end(), str.begin(), ::tolower);
keyword=keyword_alpha(keyword);
cipher55(str,keyword);
decipher55(str,keyword);
*/

while(true)
{
cout<<"\n\n>> Welcome at Simple Substitution Cipher"
<<"\n>> What do you like to do today?"
<<"\n>> 1- Cipher a message"
<<"\n>> 2- Decipher a message"
<<"\n>> 3- Main menu"
<<"\n>> ";

cin.clear();
cin>>choose;

if (choose==1)
{
    cin.ignore();
    cout<<"Please enter the message to cipher: ";getline(cin, str);
    cout<<"enter the key: ";cin>>keyword;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    keyword=keyword_alpha(keyword);

    string cipher_text = cipher55(str,keyword);
    cout<<"encrypted message: "<<cipher_text<<"\n";
    sleep(5);
}

else if (choose==2)
{
    cin.ignore();
    cout<<"Please enter the message to decipher: ";getline(cin, str);
    cout<<"enter the keyword: ";getline(cin, keyword);
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    keyword=keyword_alpha(keyword);
        
    string decipher_text = decipher55(str,keyword);
    cout<<"decipher messege is : "<<decipher_text;
    sleep(5);
}
else if (choose==3) {break;}

else {cout<<"invalid input please try again";}
cin.clear();
sleep(5);

}


return 0;
}