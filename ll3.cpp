#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

void printvect(vector<int> s)
{
    for(int i =0; i<s.size(); i++)
        cout<<s[i]<<" ";
    cout<<endl;
}

void smiledelete(string s, int a)
{
    s[a] = s[a+3];
    s[a+1] = s[a+4];
    s[a+3] = s[a+5];
}

int main()
{
    {
    //Реверс строки
    string s = "123456789";
    int j = s.length() - 1;
    for(int i = 0; i< s.length()/2; i++)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        j--;
    }
    cout<<s<<endl;
    }

    {
    //Отсортируем массив чисел sort ( ) …для отсортированного массива половину массива оставим как есть, а правую половину массива отсортируем в обратном направлении
    vector<int> ss = {11, 45, 72, 3, 1, 45, 18, 98, 66, 14};
    sort(ss.begin(), ss.end());
    printvect(ss);
    int j = ss.size() - 1;
    for(int i = ss.size()/2 + 1; i< ss.size()/2 + ss.size()/4; i++)
    {
        int temp = ss[i];
        ss[i] = ss[j];
        ss[j] = temp;
        j--;
    }
    printvect(ss);
    }

    {
    //На вход подается n чисел ( n большое ), в диапазоне от -100 до 100, вывести k самых больших, k самых маленьких чисел (p.s используете map)
    int n, k;
    cin>>n;
    cout<<endl;
    multimap<int,int> m;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        m.insert ( make_pair(temp, i) );
    }
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }
    auto it = m.begin();
    for (int i = 0; i < k; i++)
    {
        cout << it->first << " ";
        it++;
    }
    cout<<endl;
    it = m.end();
    it--; 
    for (int i = 0; i < k; i++)
    {
        cout << it->first << " ";
        it--;
    }
    cout<<endl;
    }
    
    {
    //удаление повторных пробелов
    int j = 0;
    string s = "1 2  3   4    5678   9";
    bool last = false;
    for (int i = 0; i < s.length(); i++)
    {  
        if(last && s[i] == ' ') s[j] = s[i];
        else 
        {
            s[j] = s[i];
            j++;
        }
        if(s[i] == ' ') last = true;
        else last = false; 
    }
    s.resize(j);
    cout<<s<<endl;
    }

    {
    //удаление смайликов вида :-), :-( пример (“aaa:-:-))bbb” -> “aa:-)bbb”
    string ss = ":-:-)(123456:-(:-(:-)78::-)-(910:-(";
    int i = 0, j = 0;
    while ( i < ss.length())
    {
        if(ss.substr(i,3) == ":-)" || ss.substr(i,3) == ":-(")
        {   
            i+=3;
        }
        else 
        {
            ss[j]= ss[i];
            j++;
            i++;

        }
    }
    ss.resize(j);
    cout<<ss<<endl;
    }

}