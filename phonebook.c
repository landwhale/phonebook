#include <stdio.h>
#include <string.h>

#define MAX_NUM 100

typedef struct{
    char Name[30];
    char Number[20];
    char Age[10];
}Person;

int savefile(Person *ptr, int*num);
int openfile(Person *ptr, int*num);
int insert(Person*ptr, int *num);
int delete(Person*ptr, int *num);
int search(Person*ptr, int *num);
void printALL(Person*ptr, int *num);

int main(){
    Person person[MAX_NUM];
    int input;
    int user = 0;

    openfile(person, &user);
    while(1){
        printf("1. insert \n");
        printf("2. delete \n");
        printf("3. search \n");
        printf("4. print all \n");
        printf("5. exit \n");
        printf("select : ");
        scanf("%d", &input);
        if(input == 1){
            printf("**insert**\n");
            insert(person, &user);
        }else if(input == 2){
            printf("**delete**\n");
            delete(person, &user);
        }else if(input == 3){
            printf("**search**\n");
            search(person, &user);
        }else if(input == 4){
            printf("**print all**\n");
            printALL(person, &user);
        }else if(input == 5){
            savefile(person, &user);
            return 0;
        }else{
            printf("error !\n\n");
        }
    }
    return 0;
}

int savefile(Person *ptr, int*num){
    if(*num>0){
        int i,state;
        FILE *fp =fopen("phone.txt","wt");
        if(fp ==NULL){
            printf("open error !\n");
            return 1;
        }

        for(i=0; i<*num;i++){
            fprintf(fp, "%s %s %s",ptr[i].Name,ptr[i].Number,ptr[i].Age);
            fputc('\n',fp);
        }

        state = fclose(fp);
        if(state != 0){
            printf("file close error\n");
            return 1;
        }
        printf("DATA SAVE\n");
        return 0;
    }else{
        printf("\n Exit\n");
        return 0;
    }
}

int openfile(Person*ptr, int*num){
    int state;
    char temp;
    FILE*fp = fopen("phone.txt","rt");
    if(fp==NULL){
        printf("file open error !");
        return 1;
    }
    while(1){
        fscanf(fp, "%s %s %s",ptr[*num].Name,ptr[*num].Number,ptr[*num].Age);
        if(feof(fp)!= 0) break;
        (*num)++;
    }
    state = fclose(fp);
    if(state != 0){
        printf("file close error !");
        return 1;
    }
    return 0;
}


int insert(Person*ptr, int *num){
    if(*num < MAX_NUM){
        printf("****input name !****\n\n");
        scanf("%s", ptr[*num].Name);
        printf("****input Number !**\n\n");
        scanf("%s", ptr[*num].Number);
        printf("****input Age !*****\n\n");
        scanf("%s", ptr[*num].Age);
        (*num)++;
        printf("****Data insert !***\n\n");
        return 0;
    }else if(MAX_NUM < *num){
        printf("****Data full !*****\n\n");
        return 0;
    }else{
        printf("****Data error !****\n\n");
        return 0;
    }
}

int delete(Person*ptr, int *num){
    char name[30];
    if(*num > 0){
        printf("****input name !****\n\n");
        scanf("%s", name);
        for(int i=0; i<MAX_NUM; i++){
            if(strcmp(name, ptr[i].Name)== 0){
                for(int j=i; j<MAX_NUM; j++){
                    strcpy(ptr[j].Name,ptr[j+1].Name);
                    strcpy(ptr[j].Number,ptr[j+1].Number);
                    strcpy(ptr[j].Age,ptr[j+1].Age);
                }
                (*num)--;
                printf("****Data deleted !**\n\n");
                return 0;
            }
        }
        return 0;
    }else{
        printf("****NO Data !****\n\n");
        return 0;
    }
}

int search(Person*ptr, int *num){
    char name[30];
    if(*num>0){
        printf("****input name !****\n\n");
        scanf("%s", name);
        for(int i=0; i<MAX_NUM; i++){
            if(!strcmp(name, ptr[i].Name)){
                printf("Name : %s\n", ptr[i].Name);
                printf("Number : %s\n", ptr[i].Number);
                printf("Age : %s\n", ptr[i].Age);
                return 0;
            }
        }
        return 0;
    }else{
        printf("****NOT FOUND OR NO DATA !****\n\n");
        return 0;
    }
}

void printALL(Person*ptr, int *num){
    if(*num >0){
        for(int i=0; i< *num; i++){
            printf("##########################\n");
            printf("Name : %s\n", ptr[i].Name);
            printf("Number : %s\n", ptr[i].Number);
            printf("Age : %s\n", ptr[i].Age);
            printf("##########################\n");
        }
    }else{
        printf("****NO DATA !****\n");}
}