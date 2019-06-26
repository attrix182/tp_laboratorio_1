#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

//El resto de las funciones se encuentran documentadas en LinkedList.h

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor o igual al len de la lista)
 *                   (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                    ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        ll_set_Size(this, 0);
        // this->size=0;      //los operadores flecha fueron reemplazador por setter y getters
        ll_setFirstNode(this, NULL);
        //this->pFirstNode = NULL;
    }
    return this;
}


int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = ll_get_Size(this);
    }
    return returnAux;
}



static Node* getNode(LinkedList* this, int nodeIndex)
{

    if(this == NULL || nodeIndex < 0 || nodeIndex >=ll_len(this))
    {
        return NULL;
    }

    Node *pNode = ll_get_firstNode(this);
    int actualIndex = 0;

    while(pNode != NULL)
    {
        if(actualIndex == nodeIndex)
        {
            return pNode;
        }

        actualIndex++;
        pNode = ll_get_NextNode(pNode);

    }

    return NULL;

}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{

    if(this == NULL || nodeIndex > ll_len(this) || nodeIndex < 0)
    {
        return -1;
    }

    if(nodeIndex == 0)
    {
        Node *newNode = (Node*)malloc(sizeof(Node));
        Node *auxChildren = ll_get_firstNode(this);
        ll_set_NodeElement(newNode, pElement);
        ll_setNextNode(newNode, auxChildren);
        ll_setFirstNode(this,newNode);
    }
    else
    {
        Node *newNode = (Node*)malloc(sizeof(Node));
        Node *parent = getNode(this, nodeIndex - 1);

        Node *auxNextNode = ll_get_NextNode(parent);

        ll_set_NodeElement(newNode, pElement);
        ll_setNextNode(parent, newNode);
        ll_setNextNode(newNode, auxNextNode);
    }

    ll_increase_size(this);

    return 0;

}



int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}



int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        addNode(this, ll_get_Size(this),pElement);

        return 0;
    }

    return returnAux;
}


void* ll_get(LinkedList* this, int index)
{

    void* returnAux = NULL;
    Node* pNode;

    if(this == NULL && index<0 && index > ll_len(this))
    {
        return returnAux;

    }
    pNode = getNode(this,index);
    returnAux = ll_get_NodeElement(pNode);


    return returnAux;
}



int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        pNode = getNode(this,index);
        if(pNode != NULL)
        {
            ll_set_NodeElement(pNode, pElement);
            returnAux = 0;
        }
    }

    return returnAux;
}



int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodoAremover;
    Node* pNodoAnterior;
    Node* pNodoSiguiente;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        if(ll_len(this) == 1)
        {
            ll_setFirstNode(this, NULL);
            free(getNode(this,index));
        }
        else if(index == 0 )
        {
            pNodoAremover = getNode(this,index);
            pNodoSiguiente = ll_get_NextNode(pNodoAremover);
            ll_setNextNode(pNodoAremover, pNodoSiguiente);
            free(pNodoAremover);
        }

        else
        {
            pNodoAremover = getNode(this,index);
            pNodoAnterior = getNode(this,index-1);
            pNodoSiguiente = ll_get_NextNode(pNodoAremover);
            ll_setNextNode(pNodoAnterior, pNodoSiguiente);
            free(pNodoAremover);

        }

        returnAux = 0;
        ll_decrease_size(this);
    }

    return returnAux;
}





int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;

    if(this != NULL)
    {
        for( i=0 ; i < ll_len(this); i++)
        {
            ll_remove(this,i);
        }

        returnAux = 0;
    }

    return returnAux;
}



int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;


    if(this == NULL)
    {
        return returnAux;
    }

    if(ll_clear(this) == 0)
    {
        free(this);
        returnAux = 0;
    }

    return returnAux;
}


int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* pNode;

    if(this == NULL)
    {
        return returnAux;
    }

    for(i = 0; i<ll_len(this); i++)
    {
        pNode = getNode(this,i);

        if(ll_get_NodeElement(pNode) == pElement)
        {
            returnAux = i;
            break;
        }
    }

    return returnAux;

}


int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if (this!=NULL)
    {

        if (ll_len(this)== 1)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}



int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this == NULL && index <= 0 && index >= ll_len(this))
    {
        return returnAux;
    }

    returnAux = addNode(this,index,pElement);

    return returnAux;
}



void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this == NULL && index <= 0 && index >= ll_len(this))
    {
        return returnAux;
    }

    returnAux = ll_get(this,index);
    ll_remove(this,index);

    return returnAux;
}


int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {

        if(ll_indexOf(this,pElement) == -1)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }

    return returnAux;

}


int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int tam1;
    int tam2;
    void* pElement;
    int contador = 0;

    tam1 = ll_len(this);
    tam2 = ll_len(this2);

    if(this != NULL && this2 != NULL)
    {
        returnAux = 0;
        if(tam1 >= tam2)
        {
            for(int i = 0; i<tam2; i++)
            {
                pElement = ll_get(this2,i);
                if(ll_contains(this2,pElement) == 1)
                {
                    contador++;
                }
                if(contador == tam1)
                {
                    returnAux = 1;
                }
            }
        }
    }

    return returnAux;

}


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    if (this!=NULL&&from>=0&&to<=ll_len(this))
    {
        LinkedList* newList = ll_newLinkedList();
        if (newList!=NULL)
        {
            int i;
            void* auxElement = NULL;
            for (i=from; i<=to; i++)
            {
                auxElement = ll_get(this,i);
                ll_add(newList,auxElement);
            }
        }

        cloneArray = newList;
    }
    return cloneArray;
}



LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if (this!=NULL)
    {
        cloneArray = ll_subList(this,0,ll_len(this));
    }
    return cloneArray;
}



int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    int i, j;
    void* aux;

    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        for(i = 0; i<(ll_len(this)-1); i++)
        {
            for(j = i+1; j<ll_len(this); j++ )
            {
                if(order == 1 && pFunc(ll_get(this, i), ll_get(this, j)) > 0)
                {
                    aux = ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,aux);

                }
                else if(order == 0 && pFunc(ll_get(this,i), ll_get(this,j)) < 0)
                {
                    aux = ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,aux);
                }

            }
        }


        returnAux = 0;

    }

    return returnAux;
}





// Funciones propias

int ll_increase_size(LinkedList* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        this->size +=1;
        retVal = 0;
    }
    return retVal;
}

int ll_decrease_size(LinkedList* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        this->size--;
        retVal = 0;
    }
    return retVal;
}


int ll_setFirstNode(LinkedList* this, Node* pNode)
{
    int retorno = -1;

    if(this !=NULL && pNode != NULL)
    {
        this->pFirstNode = pNode;
        retorno = 0;
    }
    return retorno;
}


int ll_setNextNode(Node* this, Node* nextNode)
{
    int retorno = -1;

    if(this !=NULL && nextNode != NULL)
    {
        this->pNextNode = nextNode;
        retorno = 0;
    }
    return retorno;
}


int ll_set_NodeElement(Node* this, void* pElement)
{
    int retorno = -1;
    if (this!=NULL)
    {
        this->pElement = pElement;
        retorno = 0;
    }
    return retorno;
}

int ll_set_Size(LinkedList* this, int size)
{
    int retorno = -1;

    if (this!=NULL)
    {
        this->size = size;
        retorno = 0;
    }
    return retorno;
}


Node* ll_get_firstNode(LinkedList* this)
{
    Node* retornoNode = NULL;
    if (this!=NULL)
    {
        retornoNode = this->pFirstNode;
    }
    return retornoNode;

}


Node* ll_get_LastNode(LinkedList* this)
{

    Node* retornoNode = NULL;
    if (this!=NULL)
    {
        if (ll_isEmpty(this)==0)
        {
            Node* lastNode = ll_get_firstNode(this);
            while (lastNode!=NULL)
            {
                retornoNode = lastNode;
                lastNode = ll_get_NextNode(retornoNode);
            }
        }
    }
    return retornoNode;
}


Node* ll_get_NextNode(Node* this)
{
    Node* retornoNode = NULL;
    if (this!=NULL)
    {
        retornoNode = this->pNextNode;
    }
    return retornoNode;


}


Node* ll_get_NodeElement(Node* this)
{
    void* ret = NULL;
    if (this!=NULL)
    {
        ret = this->pElement;
    }
    return ret;


}


int ll_get_Size(LinkedList* this)
{
    int retorno = 0;
    if (this!=NULL)
    {
        retorno = this->size;
    }
    return retorno;
}
