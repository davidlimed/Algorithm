#include <iostream>
#include <pthread.h>
#include <semaphore.h>

#include <string.h>


using namespace std;

struct S_NODE
{
    int nData;
    S_NODE * pNext;
};

struct S_LIST
{
    S_NODE * pHeadNode;
};

void CreateList(S_LIST ** ppList);
void AddData(S_LIST * pList, int nInsertData);
void DelData(S_LIST * pList, int nDelData);
bool SearchData(S_LIST * pList, int nData);
S_NODE * GetNode(S_LIST * pList, int nFindData);
void AllDelete(S_LIST * pList);
void AllPrint(S_LIST * pList);


int main()
{
    S_LIST * pList = nullptr;

    CreateList(&pList);
    AddData(pList, 3);
    AddData(pList, 5);
    AddData(pList, 6);
    AddData(pList, 1);
    AddData(pList, 2);
    AddData(pList, 0);
    AddData(pList, 11);
    AddData(pList, 32);

    AllPrint(pList);

    AllDelete(pList);
    delete pList;
    pList = nullptr;

    int a = 0;

    return 0;
}

void CreateList(S_LIST ** ppList)
{
    (*ppList) = new S_LIST;

    (*ppList)->pHeadNode = nullptr;
}

void AddData(S_LIST * pList, int nInsertData)
{
    if(!pList)
        return;

    if(!pList->pHeadNode)
    {
        S_NODE * pNode = new S_NODE();
        pNode->nData = nInsertData;
        pNode->pNext = nullptr;

        pList->pHeadNode = pNode;

        return;
    }

    S_NODE * pTempHeadNode = pList->pHeadNode;

    while(pList->pHeadNode)
    {
        if(!pList->pHeadNode->pNext)
        {
            S_NODE * pNode = new S_NODE();
            pNode->nData = nInsertData;
            pNode->pNext = nullptr;

            pList->pHeadNode->pNext = pNode;
            pList->pHeadNode = pTempHeadNode;
            break;
        }

        pList->pHeadNode = pList->pHeadNode->pNext;
    }
}

void DelData(S_LIST * pList, int nDelData)
{
    while(pList->pHeadNode)
    {
        if(pList->pHeadNode->nData == nDelData)
        {
            S_NODE * pTempNode = pList->pHeadNode->pNext;

            delete pList->pHeadNode;

            if(pTempNode)
                pList->pHeadNode = pTempNode;

            else
                pList->pHeadNode = nullptr;

            break;
        }

        pList->pHeadNode = pList->pHeadNode->pNext;
    }

    return;
}

bool SearchData(S_LIST * pList, int nSearchData)
{
    while(pList->pHeadNode)
    {
        if(pList->pHeadNode->nData == nSearchData)
            return true;

        pList->pHeadNode = pList->pHeadNode->pNext;
    }

    return false;
}

S_NODE * GetNode(S_LIST * pList, int nFindData)
{
    while(pList->pHeadNode)
    {
        if(pList->pHeadNode->nData == nFindData)
            return pList->pHeadNode;

        pList->pHeadNode = pList->pHeadNode->pNext;
    }

    return nullptr;
}

void AllDelete(S_LIST * pList)
{
    while(pList->pHeadNode)
    {
        S_NODE * pNode = pList->pHeadNode->pNext;

        delete pList->pHeadNode;
        pList->pHeadNode = pNode;
    }

    pList->pHeadNode = nullptr;
}

void AllPrint(S_LIST * pList)
{
    while(pList->pHeadNode)
    {
        cout << pList->pHeadNode->nData << endl;

        pList->pHeadNode = pList->pHeadNode->pNext;
    }
}
