#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________
/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)//OK.
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}

/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* pLst, void* pElement)//OK.
{
    int ok= -1;//Variable de retorno.

    if(pLst== NULL|| pElement== NULL){return ok;}// Si alguna PElements o pLst  son igual a NULL retorno -1.
    ok= resizeUp(pLst); if(ok== -1){return ok;}//consulto y en caso de necesitar pido memoria , si no fue posible el redimencionado retorno -1.

    *((pLst->pElements)+pLst->size)= pElement; pLst->size++; ok= 0;// pelements del indice size = pelelements, aumento size en uno ,cambio el retorno a 0.
    return ok;//retorno valor.
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* pLst)
{
    int ok= -1;

     if(pLst== NULL ){return ok;}// Si pLst es igual a NULL retorno -1.
     free(pLst->pElements); free(pLst);
     ok= 0;
    return ok;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* pLst)
{
    int len= -1;

    if(pLst== NULL){return len;}
    len= (pLst->size);

    return len;
}

/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* pLst, int index)
{
    void* element= NULL;
    if(pLst== NULL ||(index< 0||index> (pLst->size))){return element;}
    element= *(pLst->pElements + (index));
    return element;
}

/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* pLst, void* pElement)
{
    int i,ok= 0;

    if(pLst== NULL|| pElement== NULL){ ok= -1;return ok;}// Si alguna PElements o pLst  son igual a NULL retorno -1.

    for (i= 0;i< (pLst->size);i ++)
    {
        if(*(pLst->pElements+ i)== pElement){ok= 1; return ok;}
    }
    return ok;
}

/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* pLst,int index,void* pElement)
{
    int ok= -1;

    if(pLst== NULL|| pElement== NULL|| index> (pLst->size)|| index< 0){return ok;}

    if((pLst->size)== index){pLst->add(pLst,pElement);ok= 0;}
    else{*(pLst->pElements+ index)= pElement; ok= 0;}

    return ok;
}

/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* pLst,int index)
{
    int ok= -1;

    if(pLst== NULL ||index< 0 ||index> pLst->size)return ok;

    free((pLst->pElements+ index));
    pLst->size--; ok= 0;

    return ok;
}

/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* pLst)
{
    int ok= -1;

    if( pLst== NULL){return ok;}
    ok= 0;
    pLst->size= 0; pLst->reservedSize= AL_INITIAL_VALUE;
    return ok;
}

/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* pLst)
{
    ArrayList* arrayClon= NULL;

    if(pLst== NULL){return arrayClon;}

    arrayClon= al_newArrayList();
    arrayClon= pLst;

    return arrayClon;
}

/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* pLst, int index, void* pElement)
{
    int flag,ok = -1;

    if(pLst== NULL ||pElement== NULL ||index< 0||index> (pLst->size)){return ok;}

    flag= expand(pLst,index);
    pLst->set(pLst,index,pElement);
    if(flag== 0)ok= 0;

    return ok;
}

/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* pLst, void* pElement)
{
    int i,index= -1;

    if(pLst== NULL ||pElement== NULL){return index;}

    for(i=0 ;i< (pLst->size);i++)
    {
        if(*(pLst->pElements+ i)== pElement){index= i;return index;}
    }

    return index;
}

/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* pLst)
{
    int ok= -1;

    if(pLst== NULL){return ok;}

    if(pLst->size> 0 ){ok= 0; return ok;}
    else{ ok= 1;return ok;}
}

/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* pLst,int index)
{
    void* ElementRemoved= NULL;

    if(pLst== NULL ||index< 0||index> (pLst->size)){return ElementRemoved;}
    ElementRemoved= al_get(pLst,index); pLst->remove(pLst,index);

 return ElementRemoved;
}

/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* pLst,int from,int to)
{
    int i;
    void* subLst= NULL;

    if(pLst== NULL ||from< 0||from> (pLst->size) ||to< 0 ||to> (pLst->size) ||from> to ){return subLst;}

    subLst= al_newArrayList();

    if(from== to){pLst->add(subLst,pLst->get(pLst,from));return subLst;}
    for(i=from; i< to;i++)
    {
        pLst->add(subLst,pLst->get(pLst,i));
    }
    return subLst;
}

/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* pLst,ArrayList* pLst2)
{
    int ok= -1;
    int flag,i;

    if(pLst2== NULL || pLst== NULL){return ok;}

    ok= 1;
    for(i= 0;i< (pLst2->size);i++)
    {
        flag= al_contains(pLst,pLst2->get(pLst2,i));
        if(flag== 0){ok= flag;return ok;}
    }
    return ok;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* pLst, int (*pFunc)(void* ,void*), int order)
{
    int ok=- 1;
    int i,j;
    void* auxEelemt;

    if(pLst== NULL ||pFunc== NULL ||(order!= 0&& order!= 1)){return ok;}

    ok= 0;
    for(i= 0;i< (pLst->size -1);i++)
    {
        for(j= i+1;j<(pLst->size);j++)
        {
            if(pFunc(pLst->get(pLst,i),pLst->get(pLst,j))== -1 &&order== 0)
            {
                auxEelemt= pLst->get(pLst,j);

                pLst->set(pLst,j,pLst->get(pLst,i)); pLst->set(pLst,i,auxEelemt);
            }
            else if(pFunc(pLst->get(pLst,i),pLst->get(pLst,j))== 1 &&order== 1)
                    {
                        auxEelemt= pLst->get(pLst,i);

                        pLst->set(pLst,i,pLst->get(pLst,j)); pLst->set(pLst,j,auxEelemt);
                    }
        }
    }

    return ok;
}



/**< variables auxiliares------------------------------------------------------ */


/** \brief Decreases the quantity of elements by quantities igules to AL_INITIAL_VALUE.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeDown(ArrayList* pLst)
{
    void* APelem= NULL;
    int ok= -1;

    if(pLst== NULL){return ok;}
    if(pLst->reservedSize- pLst->size> AL_INITIAL_VALUE)
    {
        APelem= (void**)realloc(pLst->pElements,(pLst->reservedSize- AL_INITIAL_VALUE)*sizeof(void*));
        if(APelem== NULL){return ok;}
        else{pLst->pElements= APelem; pLst->reservedSize=- AL_INITIAL_VALUE; ok= 0;}
    }
    else{ok= 0; return ok;}

    return ok;
}

/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* pLst)
{
    void** APelem= NULL;//declaro puneto a puntero void =MUUL
    int ok= -1;// variable de retorno.

    if(pLst== NULL){return ok;}// si la direccion del arraylist es NULL retorno -1.
    if(pLst->size>= pLst->reservedSize)// Si el tamaño del array es igual a la cantidad de espacio recervado ingresa.
    {
        APelem= (void**)realloc(pLst->pElements,((pLst->size+ AL_INCREMENT )*sizeof(void*))); //recerva con el doble púntero a void auxiliar un espacio igual tamaño que pelements + 10.
        if(APelem== NULL)return ok;// si no pudo redimencionar la memoria retorno -1.
        else{pLst->pElements= APelem; pLst->reservedSize=+ AL_INCREMENT; ok= 0;}//asigno el nuevo espacio de memoria a pelemnts y cambio el valor de retorno a 0.
    }
    else{ok= 0; return ok;}

    return ok;// retorno 0.
}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* pLst,int index)
{
    int i,ok= -1;

    if(pLst== NULL|| index< 0||index> (pLst->size)){return ok;}

    if(index== (pLst->size)){pLst->add(pLst,index); ok= 0; return ok;}

    for(i=(pLst->size);i> index;i--)
    {
        pLst->set(pLst,i,(pLst->pElements+ i-1));
    }
    ok= 0;

    return ok;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* pLst,int index)
{
    int i,ok= -1;

    if(pLst== NULL ||index< 0 ||index>= (pLst->size)){return ok;}

    for(i=index;i< (pLst->size);i++)
    {
        pLst->set(pLst,i,(pLst->pElements+ i+1));
    }
    ok= resizeDown(pLst);
    //ok= 0;

    return ok;
}
