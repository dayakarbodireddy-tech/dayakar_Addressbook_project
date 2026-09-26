#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include<ctype.h>
//#include "populate.h"
int validateName(char name[]);
int validatephone(char phone[]);
int validateemail(char email[]);
int validateName(char name[])
{
    int nameflag=1;
    if(strlen(name)<2)
    {
        nameflag=0;
    }
    for(int i=0;name[i]!='\0';i++)
    {
        if(!isalnum(name[i])&&name[i]!=' ')
        {
            nameflag=0;
        }
    }
    return nameflag;
    
}
int validatephone(char phone[])
{
    int phoneflag=1;
  if(strlen(phone)!=10) 
  {
     phoneflag=0;
  }
  if(phone[0]<'6'||phone[0]>'9')
  {
    phoneflag=0;
  }
  for(int i=0;phone[i]!='\0';i++)
  {
    if(!isdigit(phone[i]))
    {
        phoneflag=0;
        break;
    }
  }
  
  return phoneflag;
}
int validateemail(char email[])
{
    int emailflag=1;
    for(int i=0;email[i]!='\0';i++)
    {
    if(isupper(email[i]))
    {
        emailflag=0;
    }
    }

    int len=strlen(email);
    if(len<4||strcmp(email+len-4,".com")!=0)
    {
      emailflag=0;
    }
    char *at=strchr(email,'@');
    char *at1=strrchr(email,'@');
    char *dot=strstr(email,".com");
    if(at!=NULL&&dot!=NULL&&dot<=at+1)
    {
        emailflag=0;
    }
    if(at==NULL)
    {
        emailflag=0;
    }
    if(dot==NULL)
    {
        emailflag=0;
    }
    if(at==email)
    {
        emailflag=0;
    }
    if(at!=at1)
    {
       emailflag=0;
    }
    return emailflag;

}  


void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    for(int i=0;i<addressBook->contactCount-1;i++)
    {
        for(int j=i+1;j<addressBook->contactCount;j++)
        {
            if(strcmp(addressBook->contacts[i].name,addressBook->contacts[j].name)>0)
            {
                Contact temp=addressBook->contacts[i];
                addressBook->contacts[i]=addressBook->contacts[j];
                addressBook->contacts[j]=temp;

            }
        }
    }
    printf("Name\tcontact_num\temail\n");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        printf("%s\t\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
}
void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    int flag=0;
    if(addressBook->contactCount>=MAX_CONTACTS)
    {
        printf("address book is full\n");
        return;
    }
    printf("Enter the name of contact: ");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
   
    if(validateName(addressBook->contacts[addressBook->contactCount].name))
    {
        while(1)
        {
        printf("enter the contact number: ");
        scanf("%s",addressBook->contacts[addressBook->contactCount].phone);
        if(validatephone(addressBook->contacts[addressBook->contactCount].phone))
        {
            while(1)
            {
            printf("enter the email id: ");
            scanf("%s",addressBook->contacts[addressBook->contactCount].email);
            if(validateemail(addressBook->contacts[addressBook->contactCount].email))
            {
                printf("cantact name : %s\n",addressBook->contacts[addressBook->contactCount].name);
                printf("cantact number : %s\n",addressBook->contacts[addressBook->contactCount].phone);
                printf("cantact email : %s\n",addressBook->contacts[addressBook->contactCount].email);
                addressBook->contactCount++;
                break;
                
            }else{
                printf("invalid email\n");
                
            }
           
        }
        break;
        }else{
            printf("invalid contact number\n");
        }
    
    }
    }else{
        printf("invalid input\n");
    }
    


    
    
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int found=0;
    int choice;
    printf("search contact by : \n");
    printf("1.NAME\n");
    printf("2.PHONE_NUMBER\n");
    printf("3.EMAIL\n");
    printf("enter the choice :\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: 
        char search_name[25];
        while(1)
        {
            found=0;
     printf("enter the search name : ");
     scanf(" %[^\n]",search_name);
     for(int i=0;i<addressBook->contactCount;i++)
     {
        if(strcmp(addressBook->contacts[i].name,search_name)==0)
        {
            found=1;
            printf("%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        
    }
    if(found==1)
        {
            break;
        }else{
            printf("contact search name not found\n");
        }
    }
    break;
    
        case 2:
        char search_phone[11];
        while(1)
        {
            found=0;
     printf("enter the search phone number : ");
     scanf("%s",search_phone);
     for(int i=0;i<addressBook->contactCount;i++)
     {
        if(strcmp(addressBook->contacts[i].phone,search_phone)==0)
        {
            found=1;
            printf("%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        
        
        
    }
    if(found==1)
        {
            break;
        }else{
            printf("contact phone number not found\n ");
        }
    }
    break;
    
     case 3:
     char search_email[50];
     while(1)
     {
        found=0;
     printf("enter the search email : ");
     scanf("%s",search_email);
     for(int i=0;i<addressBook->contactCount;i++)
     {
        if(strcmp(addressBook->contacts[i].email,search_email)==0)
        {
            found=1;
            printf("%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
        
        
    }
    if(found==1)
    {
        break;
    }else{
        printf("contact email not found\n");
    }
}
break;
    
     default:printf("invalid search input\n");
        
}

     
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   
}
