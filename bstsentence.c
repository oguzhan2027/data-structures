#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 9


struct node {
    char *value;            
    struct node *p_left;
    struct node *p_right;
};


typedef int (*Compare)(const char *, const char *);


void insert(char* key, struct node** leaf, Compare cmp)
{
    int res;
    if( *leaf == NULL ) {
        *leaf = (struct node*) malloc( sizeof( struct node ) );
        (*leaf)->value = malloc( strlen (key) +1 );     
        strcpy ((*leaf)->value, key);                   
        (*leaf)->p_left = NULL;
        (*leaf)->p_right = NULL;
       
    } else {
        res = cmp (key, (*leaf)->value);
        if( res < 0)
            insert( key, &(*leaf)->p_left, cmp);
        else if( res > 0)
            insert( key, &(*leaf)->p_right, cmp);
        else                                            
            printf ("Key '%s' already in tree\n", key);
    }
}


int CmpStr(const char *a, const char *b)
{
    return (strcmp (a, b));     
}

char *input( void )
{
    static char line[MAXLEN+1];          
    printf("Please enter a string : ");
    fgets( line, sizeof line, stdin );
    return ( strtok(line, "\n" ));    
}


void in_order(struct node *root)
{
    if( root != NULL ) {
        in_order(root->p_left);
        printf("   %s\n", root->value);     
        in_order(root->p_right);
    }
}

//searches elements in the tree
void search(char* key, struct node* leaf, Compare cmp)  
{
    int res;
    if( leaf != NULL ) {
        res = cmp(key, leaf->value);
        if( res < 0)
            search( key, leaf->p_left, cmp);
        else if( res > 0)
            search( key, leaf->p_right, cmp);
        else
            printf("\n'%s' found!\n", key);     
    }
    else printf("\nNot in tree\n");
    return;
}

void delete_tree(struct node** leaf)
{
    if( *leaf != NULL ) {
        delete_tree(&(*leaf)->p_left);
        delete_tree(&(*leaf)->p_right);
        free( (*leaf)->value );         
        free( (*leaf) );
    }
}


void menu()
{
    printf("\nPress 'i' to insert an element\n");
    printf("Press 's' to search for an element\n");
    printf("Press 'p' to print the tree inorder\n");
    printf("Press 'f' to destroy current tree\n");
    printf("Press 'q' to quit\n");
}

int main()
{
    struct node *p_root = NULL;
    char *value;
    char option = 'x';

    while( option != 'q' ) {
        
        menu();

        
        option = getch();          

        if( option == 'i') {
            value = input();
            printf ("Inserting %s\n", value);
            insert(value,  &p_root, (Compare)CmpStr);
        }
        else if( option == 's' ) {
            value = input();
            search(value, p_root, (Compare)CmpStr);     
        }
        else if( option == 'p' ) {
            in_order(p_root);
        }
        else if( option == 'f' ) {
            delete_tree(&p_root);
            printf("Tree destroyed");
            p_root = NULL;
        }
        else if( option == 'q' ) {
            printf("Quitting");
        }
    }
return 0;
}
