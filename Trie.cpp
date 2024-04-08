#include <iostream> 
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(TrieNode *root, string word)
    {
        if(word.length()==0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0]-'A';
        TrieNode *child;

        if(root->children[index]!=NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insert(child,word.substr(1));
    }

    void TrieInsertion(string word)
    {
        insert(root, word);
    }

    bool search(TrieNode *root,string word)
    {
        if(word.length()==0)
        {
            return root->isTerminal;
        }

        int index =word[0]-'A';

        TrieNode *child;

        if(root->children[index]!=NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }

        return search(child,word.substr(1));
    }

    bool TrieSearch(string word)
    {
        return search(root, word);
    }

    void remove(TrieNode *root,string word)
    {
        if(word.length()==0)
        {
            root->isTerminal = false;
            return;
        }

        int index =word[0]-'A';

        TrieNode *child;

        if(root->children[index]!=NULL)
        {
            child = root->children[index];
        }

        remove(child,word.substr(1));
    }

    void TrieRemove(string word)
    {
        remove(root, word);
    }
};

int main()
{
    Trie *t = new Trie();

    t->TrieInsertion("ABCD"); 
    t->TrieInsertion("XYZ");
    cout<<t->TrieSearch("ABCD")<<endl;
    t->TrieRemove("ABCD");
    cout<<t->TrieSearch("ABCD")<<endl;
    cout<<t->TrieSearch("XYZ")<<endl;
    return 0;
}