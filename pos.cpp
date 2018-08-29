#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
using namespace std;
const int childCount=100;
int counter()
{
 static int count=0;
 count++;
}
//node defination
struct node{
    time_t timestamp;
    string data;
    int nodeNumber;
    string nodeId;
    string referenceNodeId;
    string genesisReferenceNodeId;
    string HashValue;
    string genesisReferenceNodeId[];
    node *childReferenceNodeId[];
    int childNum;

};
//data defination
struct data{
    int id;
    float value;
    string name;
};
//generate random strings
string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}
//main
int main(){
    struct node *root=NULL;
    do(){
        cout<<"1 for creating Genesis Node"<<endl;
        cout<<"2 for for creating child"<<endl;
        cout<<"3 for for creating child"<<endl;
        cout<<"4 for for encrypting the node"<<endl;
        cout<<"5 verify the owner of the node"<<endl;
        cout<<"6 Edit the value of a node"<<endl;
        cout<<"7 Transfer ownership of the node"<<endl;
        cout<<"0 to exit"<<endl;
        int n;
        cin>>n;
        switch(n){
            case 1:
                if(node==NULL){
                    int id; float value; string name;
                    struct data* data = (struct data*)malloc(sizeof(struct data));
                    cout<<"Enter Owner id, value, owner name one by one";
                    cin>>data->id;
                    cin>>data->value;
                    cin>>data->name;
                    node=createGenesis(data);
                }
                else{
                    cout<<"Can't create a gensis node as it already exists";
                }
                break;
            case 2:
                if(node==NULL){
                    cout<<"first create a genesis node"<<endl;

                }
                else{
                    struct data* data = (struct data*)malloc(sizeof(struct data));
                    cout<<"Enter Owner id, value, owner name one by one";
                    cin>>data->id;
                    cin>>data->value;
                    cin>>data->name;
                    cout<<"Enter node Number to insert into";
                    int nodeId;
                    cin>>nodeId;//todo : check validity of nodeid, if already exists;
                    struct node* ParentNode = findNodeByNodeNumber(nodeId);
                    createChild(data,Parentnode,node);
                }
                break;
            case 3:
                if(node==NULL){
                    cout<<"first create a genesis node"<<endl;

                }
                else{
                    struct data* data = (struct data*)malloc(sizeof(struct data));
                    cout<<"Enter Owner id, value, owner name one by one";
                    cin>>data->id;
                    cin>>data->value;
                    cin>>data->name;
                    cout<<"Enter node Number to insert into";
                    int nodeId;
                    cin>>nodeId;//todo : check validity of nodeid, if already exists;
                    struct node* ParentNode = findNodeByNodeNumber(nodeId);
                    createChild(data,Parentnode,node);
                }
                break;
            case 4:
                cout<<"Enter node Number to encrypt";
                int nodeId;
                cin>>nodeId;//todo : check validity of nodeid, if already exists;
                struct node* node = findNodeByNodeNumber(nodeId);
                cout<<"Key for Decryption is "<<encryptHashValue(node)<<endl;
                break;
            case 5:
                cout<<"Enter node Number to insert into";
                int nodeId;
                cin>>nodeId;//todo : check validity of nodeid, if already exists;
                
                string key;
                cout<<"Enter Decryption Key";
                if(checkValidNodeAuthority(key,findNodeByNodeNumber(nodeId)))
                    cout<<"Correct Owner of Node";
                else
                    cout<<"Inncoorect Owner of Node";
                break;
            case 6:
                cout<<"Enter node Number to edit value";
                int nodeId;
                cin>>nodeId;//todo : check validity of nodeid, if already exists;
                struct node* node = findNodeByNodeNumber(nodeId);
                //todo :: create another function and pass the node as param to create Update from the user;
                //recompile the node with new hash n return new decryption key
                cout<<"New Key for Decryption is "<<encryptHashValue(node)<<endl;
                break;
            case 7:
                //todo :: transfer the owner of the node

        }
    }
    while(n>0);
}
//todo convert all the other datatypes in string format AND then concat it
string encryptNode(node* node){
    //encrypt the node with the values in it and store them in HASHVALUE of the node
    //and return the key for that node
}
bool checkValidNodeAuthority(string key, node* node){
        //check the key with the hash value of node and try to decrypt using the same key, if success, return true, else return false;
}
//create genesis
struct node* createGenesis(data *data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->timestamp=time(0);
    node->data=data;
    node->nodeNumber=counter();
    node->nodeId=random_string(32);
    node->referenceNodeId=NULL;
    node->genesisReferenceNodeId=NULL;
    // child array
    node *childReferenceNodeId[] = new node*[childCount];// can use vector here
    node->childReferenceNodeId=childReferenceNodeId;
    node->HashValue=NULL;
    cout<<"Node inserted with node number"<<node->nodeId<<endl;
    return node;
}
void createChild(data *data, node* ParentNode,node* Genesis){

    if(checkValid(data->value,Parentnode))
    {
        struct node* node = (struct node*)malloc(sizeof(struct node));
        hashwrapper *myWrapper = new md5wrapper();
        node->timestamp=time(0);
        node->data=data;
        node->nodeNumber=counter();
        node->nodeId=random_string(32);
        node->referenceNodeId=Parentnode;
        node->genesisReferenceNodeId=Gensis;
        node *childReferenceNodeId[] = new node*[childCount];// can use vector here
        node->childReferenceNodeId=childReferenceNodeId;
        node->HashValue=NULL;
        //todo :: insert into childReferenceNodeId in the ParentNode
        cout<<"Node inserted with node number"<<node->nodeId<<endl;

        }
    else{
        cout<<"the value exceeds the limit of this node";
        return;
    }
}
bool checkValid(float value, node* ParentNode){
    node *childReferenceNodeId[]=ParentNode->childReferenceNodeId;
    //itterate over the child nodes in the records and decrypt them and add the values;
    //now check whether the value is less or greater and accordingly return true/false;
}
struct node* findNodeByNodeNumber(int nodeId){
    //return from here the node which has the same nodeId
}
