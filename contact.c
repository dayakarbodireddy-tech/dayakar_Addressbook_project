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
    // Sort contacts based on the choosen criteria
//      int cricteria
//     printf("Sort based on :\n1.Name\n2.phone\n3.email\n");/*
//     scanf("%d",&criteria);
//     if 1 
//     sorted based on name
//     if 2
//     sorted based on phone
//     if 3
//     sorted on email
//     */
//     for(int i=0;i<addressBook->contactCount;i++)
//     {
//         printf("%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
//     }
    
    
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
//     if(flag==1)
//     {
//         printf("Invalid input\n");
       
//     }else{
        
//         while(1)
//         {
//             flag=0;
//         printf("enter the contact number: "); 
//         scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);
//         if(strlen(addressBook->contacts[addressBook->contactCount].phone)!=10)
//         {
//             flag=1;
//         }
//         if(addressBook->contacts[addressBook->contactCount].phone[0]<'6'||addressBook->contacts[addressBook->contactCount].phone[0]>'9')
//         {
//             flag=1;
//         }
    
//         if(flag==1)
//         {
//            printf("invalid number\n");
//         }else{
//             printf("enter the email id: ");
//             scanf(" %s",addressBook->contacts[addressBook->contactCount].email);
//             break;
//         }
//         if()
//     }
    
// }


    
    
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    // printf("Search based on \n1.Name\n2.phone,3.email\n");
    // scanf();
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
   
}
