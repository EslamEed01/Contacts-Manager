#include<iostream>
#include <string>
#include <conio.h>

using namespace std;
class Node
{
public:
    string name;
    string phone;
    Node* left, * right;

    Node(string n,string p)//constructor
    {
        name=n;
        phone =p;
        left = right = NULL;
    }
};

class BST {
public:
    Node *root;// pointer to root

    BST() //constructor
    {
        root = NULL;
    }

    Node *Insert(Node *r, string name,string phone) {
        if (r == NULL) {
            Node *newnode = new Node(name,phone);
            r = newnode;
        } else if (name < r->name)
            r->left = Insert(r->left, name,phone);
        else if(name>r->name)
            r->right = Insert(r->right, name,phone);
    else
    r->phone=phone;

        return r;
    }

    /*void Preorder(Node *r) // root ->left->right
    {
        if (r == NULL)
            return;
        cout << r->name<<"\t" <<r->phone<<endl;
        Preorder(r->left);
        Preorder(r->right);
    }*/

    void Inorder(Node *r) // left->root -> right
    {
        if (r == NULL)
            return;
        Inorder(r->left);
        cout << r->name<<"\t" <<r->phone<<endl;
        Inorder(r->right);
    }


        Node *Search(Node *r, string key) {
            if (r == NULL)
                return NULL;
            else if (key == r->name)
                return r;
            else if (key < r->name)
                return Search(r->left, key);
            else
                return Search(r->right, key);

        }


       /* Node *Findmin(Node *r) {
            if (r == NULL)
                return NULL;
            else if (r->left == NULL)
                return r;
            else
                return Findmin(r->left);
        }*/

        Node *Findmax(Node *r)
         {
            if (r == NULL)
                return NULL;
            else if (r->right == NULL)
                return r;
            else
                return Findmax(r->right);
        }

        Node *Delete(Node *r, string name) {
            if (r == NULL)
                return NULL;
            else if (name < r->name)
                r->left = Delete(r->left, name);
            else if (name > r->name)
                r->right = Delete(r->right, name);
            else {
                if (r->left == NULL && r->right == NULL)//leaf node
                {
                    delete r;
                    r = NULL;
                } else if (r->left != NULL && r->right == NULL)// one child from left
                {
                    r->name = r->left->name;
                    r->phone = r->left->phone;
                    delete r->left;
                    r->left = NULL;
                } else if (r->left == NULL && r->right != NULL)// one child from right
                {
                    r->name = r->right->name;
                    r->phone = r->right->phone;
                    delete r->right;
                    r->right = NULL;
                } else {
                    Node *max = Findmax(r->left);// two children
                    r->name = max->name;
                    r->phone = max->phone;
                    r->left = Delete(r->left, max->name);

                }


            }
            return r;
        }
        Node* Changephone(Node* r, string  name , string newphone)
        {
        Node* target = Search(root,name);
        if(target == NULL)
            cout<<"Not exist"<<endl;
        else {
            target->phone = newphone;
            cout << target->name << "\t" << target->phone<<endl;
        }

        }

    void Insert( string name, string phone)// fun overloading for class user
    {
        root = Insert(root, name,phone);
    }


      

        void Delete(string kname) // fun overloading for class user
        {
            root = Delete(root, kname);
        }

        void Search(string key) // fun overloading for class user
        {
            Node *result = Search(root, key);
            if (result == NULL)
                cout << "Contact is Not found" << endl;
            else
                cout << result->name<<"\t"<< result->phone<<endl;

        }
    };

    int main() {
        BST tree;
        int choice;
        string name,phone,key;
        cout << " ********************** Contacts Manager **********************\n";
        menu1:
        cout << " 1.Add New Contact \n";
        cout << " 2. Search for Contact \n";
        cout << " 3. Delete contact \n";//
        cout << " 4. Change contact number \n";
        cout << " 5. Display Sorted Contacts\n";
        cout << " \n Enter you choice >>> \n";
        cin>>choice;
        switch (choice)
        {
            case 1:

                cout << " Enter Name :" << endl;
                cin>>name;
                cout << " Enter Phone Number : " << endl;
                cin >> phone;
                tree.Insert(name, phone);
                cout << " Added Successfully" << endl;
                 getch();
                system("cls");
               
                goto menu1;
              
            case 2:
                cout<<"Enter Name you want to search : "<<endl;
                cin>>key;
                cout<<"Name"<<"\t"<<"Phone Number"<<endl;
                cout<<"******************************"<<endl;
                tree.Search(key);
                 getch();
               system("cls");

                goto menu1;

                case 3:
                cout<<"Enter Contact you want to delete :"<<endl;
                cin>>name;
                tree.Delete(name);
                cout<<"deleted Successfully";
                getch();
               system("cls");

                goto menu1;


               
            case 4:
                cout<<" Enter Contact Name :"<<endl;
                cin>>name;
                cout<<"Enter New Number: "<<endl;
                cin>>phone;
                cout<<"Changed Successfully\n";
                tree.Changephone(tree.root,name,phone);
                getch();
                system("cls");

                goto menu1;
            
            

             case 5:
                cout<<"******************************"<<endl;
                cout<<"Name"<<"\t"<<"Phone Number"<<endl;
                cout<<"******************************"<<endl;
                tree.Inorder(tree.root);
                getch();
                system("cls");

                goto menu1;

            default:
                cout<<" Invalid Choice"<<endl;
                getch();
                system("cls");

                goto menu1;
  


        }





    }