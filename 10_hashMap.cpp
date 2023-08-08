#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100

// �����ϣ��ṹ
typedef struct {
    int key;
    int value;
} HashEntry;

typedef struct {
    HashEntry* data[TABLE_SIZE];
} HashMap;

//��ϣ����
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

//�������ϣ��ͻ
int hashCollision(int key){
    return 0;
}

//��ʼ����ϣ��
HashMap *createHashmap(){
    HashMap *hashMap=(HashMap *)malloc(sizeof(HashMap));
    for(int i=0;i<TABLE_SIZE;i++){
    	hashMap->data[i]=NULL;
	}
    return hashMap;
}

//����ֵ
void setValue(HashMap* table, int key, int value) {
    int index = hashFunction(key);
    HashEntry* entry = (HashEntry*)malloc(sizeof(HashEntry));
    entry->key = key;
    entry->value = value;
    table->data[index] = entry;
}

//��ȡֵ
int getValue(HashMap* table,int key){
    int retValue;
    int index = hashFunction(key);
    if(table->data[index]!=NULL){
        retValue=table->data[index]->value;
    }
    return  retValue;
}

//ɾ��ֵ
void deleteHash(HashMap* table, int key) {
    int index = hashFunction(key);
    if (table->data[index] != NULL) {
        free(table->data[index]);
        table->data[index] = NULL;
    }
}

//���� 
void traverseHashMap(HashMap* table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table->data[i] != NULL) {
            printf("Index %d: Key = %d, Value = %d\n", i, table->data[i]->key, table->data[i]->value);
        }
    }
}


int main(){
    HashMap *hash=createHashmap();
    setValue(hash,8,1008);
    setValue(hash,99,1009);
    setValue(hash,198,19999);
    int ret;
    ret=getValue(hash,198);
    printf("%d\n",ret);
    ret= getValue(hash,99);
    printf("%d\n",ret);
    traverseHashMap(hash);
    return 0;
}
