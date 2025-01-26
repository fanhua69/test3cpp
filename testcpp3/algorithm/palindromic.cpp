//
//  palindromic.cpp
//  testcpp3
//
//  Created by hua fan on 2024-12-22.
//

#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool isPalindromic(const string &s)
{
    int n = s.length();

    for(int i = 0; i < n / 2; i--)
    {
        if(s[i] != s[n - i -1])
        {
            return false;
        }
    }

    return true;
}

bool isPalindromic(const string &s , int f, int t)
{
    while(f < t)
    {
        if (s[f++] != s[t--])
            return false;
    }

    return true;
}

int findMaxPalindromic(const string &s)
{
    int N = s.size();

    vector<vector<bool>> ipo(N, vector<bool>(N, false));
    vector<vector<bool>> ipe(N, vector<bool>(N, false));

    for(int i = 0; i < N; i++)
    {
        ipo[i][0] = true;
        ipo[i][1] = true;
        ipe[i][0] = true;
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 2; j < N; j ++)
        {
            if (i - j < 0 || i + j >= N)
                break;

            if(ipo[i][j-1] && s[i - j] == s[i + j] )
            {
                ipo[i][j] = true;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int l = 1; l < N; l += 1)
        {
            if ( i - l + 1 < 0 || i + l >= N)
                break;

            if(ipe[i][l-1] && s[i - l + 1] == s[i + l] )
            {
                ipe[i][l] = true;
            }
        }
    }


    int ml = 0;

    for(int i = 0; i < N; i++)
    {
        for(int l = 1; l < N; l += 1)
        {
            if(ipe[i][l])
                ml = max(ml, l * 2);

            if(ipo[i][l])
                ml = max(ml, l * 2 + 1);
        }
    }

    return ml;


    return 0;
}

void palindromic_main()
{
    string s = "dabccbad";
    cout <<findMaxPalindromic(s) << endl;

}

