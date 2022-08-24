#include <iostream>
#include <string>

using namespace std;

#define NO_CHARS 256

int getNextState(string pat, int state, int nc)
{
    int pat_size = pat.size();
    if(state < pat_size && nc == pat[state])
        return state+1;
    
    int i, ns = 0;

    for(ns=state; ns>0; ns--){
        if(pat[ns-1] == nc)
        {
            for(i=0; i<ns-1; i++){
                if(pat[i] != pat[state-ns+1+i])
                    break;
            }

            if(i == ns-1)
                return ns;
        }
    }

    return 0;
}

void computeTF(string pet, int FA[][NO_CHARS])
{
    int pet_size = pet.size();
    int state, nc;

    for(state=0; state<=pet_size; state++){
        for(nc=0; nc<NO_CHARS; nc++){
            FA[state][nc] = getNextState(pet, state, nc);
        }
    }
}

void search(string pet, string txt)
{
    int pet_size = pet.size();
    int txt_size = txt.size();

    int state = 0;
    int FA[pet_size+1][NO_CHARS];

    computeTF(pet, FA);

    for(int i=0; i<txt_size; i++){
        state = FA[state][txt[i]];
        if(state == pet_size)
        {
            cout << "pattern found at index" << i-pet_size+1 << endl;
            return;
        }
    }

    cout << "pattern not found!" << endl;
}

int main()
{
    string txt = "AABAACAADAABAAABAA";
    string pet = "ACAAD";
    search(pet, txt);
    return 0;
}

