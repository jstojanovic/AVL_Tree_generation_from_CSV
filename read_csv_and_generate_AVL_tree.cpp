#include<iostream>
#include<fstream>
#include<vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct Instanca
{
    string Name,	
        Age	,
        Nationality,	
        Overall	,
        Club	,
        Value	,
        Wage	,
        Preferred_Foot,	
        Position	,
        Jersey_Number,	
        Joined	,
        Contract_Valid_Until,	
        Height	,
        Weight	,
        BallControl,	
        SprintSpeed	,
        Agility	,
        ShotPower,	
        Jumping	,
        Stamina	,
        Strength,	
        Release_Clause;
};
struct Node
{
    string key;
    Instanca podatak;
    int height;
    Node* left;
    Node* right;
    Node(Instanca inst)
    {
        key = inst.Nationality;
        podatak = inst;
        height = 1;
        left = NULL;
        right = NULL;
    }
};
Node* Dodaj(Node* node, Instanca inst)
{
    if(node==NULL) 
        node = new Node(inst);

    else if(inst.Nationality < node->key)
        node->left = Dodaj(node->left, inst);
    else
        node->right = Dodaj(node->right, inst);
    
    return node;
}
void LijevaRotacija(Node*& node)
{
    Node* temp  = node->left;
    node->left= temp->right;
    temp->right = node;
    node = temp;
}

void DesnaRotacija(Node*& node)
{
    Node* temp  = node->right;
    node->right = temp->left;
    temp->left= node;
    node = temp;
}

void LijevaRotacija2x(Node*& node)
{
    DesnaRotacija(node->left);
    LijevaRotacija (node);
}

void DesnaRotacija2x(Node*& node)
{
    LijevaRotacija(node->right);
    DesnaRotacija(node);
}

int Visina(Node* node)
{
    if (node == NULL) return -1;
    else
    {
        int LVisina= Visina(node->left);
        int DVisina = Visina(node->right);
        if(LVisina>DVisina) return LVisina+1;
        else return DVisina+1;
    }
}

Node* DodajAVL(Node*& node, Instanca x)
{
    if(node == NULL)  // (1) If we are at the end of the tree place the value
        node = new Node(x);
    else if(x.Nationality < node->key)   //(2) otherwise go left if smaller
    {
        DodajAVL(node->left, x);
        if(Visina(node->left) - Visina(node->right) == 2)
        {
            if(x.Nationality < node->left->key)
                LijevaRotacija(node);
            else
                LijevaRotacija2x(node);
        }
    }
    else if(x.Nationality > node->key)  // (3) otherwise go right if bigger
    {
        DodajAVL(node->right, x);
        if(Visina(node->right) - Visina(node->left) == 2)
        {
            if(x.Nationality > node->right->key)
                DesnaRotacija(node);
            else
                DesnaRotacija2x(node);
        }
    }
    return node;
}
void Inorder(Node* node)
{
    if (node == NULL) return;
    Inorder(node->left);
    cout << node->key<<" ";
    Inorder(node->right);
}
void Preorder(Node* node)
{
    if (node == NULL) return; 
    cout << node->podatak.Name << " ";	
    cout << node->podatak.Age << " ";
    cout << node->podatak.Nationality << " ";	
    cout << node->podatak.Overall << " ";
    cout << node->podatak.Club << " ";
    cout << node->podatak.Value << " ";
    cout << node->podatak.Wage	 << " ";
    cout << node->podatak.Preferred_Foot << " ";	
    cout << node->podatak.Position	 << " ";
    cout << node->podatak.Jersey_Number << " ";
    cout << node->podatak.Joined	 << " ";
    cout << node->podatak.Contract_Valid_Until << " ";	
    cout << node->podatak.Height << " ";
    cout << node->podatak.Weight << " ";
    cout << node->podatak.BallControl << " ";
    cout << node->podatak.SprintSpeed << " ";
    cout << node->podatak.Agility << " ";
    cout << node->podatak.ShotPower << " ";
    cout << node->podatak.Jumping << " ";
    cout << node->podatak.Stamina << " ";
    cout << node->podatak.Strength << " ";
    cout << node->podatak.Release_Clause << " "; 
    cout<<endl;
    Preorder(node->left);
    Preorder(node->right);
}
void Ucitaj_u_vektor(vector<Instanca> &InstanceS)
{
    string file_name = "Skup_podataka.csv";
    struct Instanca inst; 
    vector<vector<string>> sadrzaj;
    vector<string> redak;
    string line, word;
     
    fstream file (file_name, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            redak.clear();
            stringstream str(line);
        while(getline(str, word, ','))
            redak.push_back(word);
        
        sadrzaj.push_back(redak);
        }   
    }
    else
        cout<<"Could not open the file\n";
     
    for(int i=0;i<sadrzaj.size();i++)
    {
    for(int j=0;j<sadrzaj[i].size();j++)
        {
        switch(j){
        case 0:
        inst.Name = sadrzaj[i][j];
        break;
        case 1:	
        inst.Age = sadrzaj[i][j];
        break;
        case 2:	
        inst.Nationality = sadrzaj[i][j];
        break;
        case 3:
        inst.Overall = sadrzaj[i][j];
        break;
        case 4:
        inst.Club = sadrzaj[i][j];
        break;
        case 5:
        inst.Value = sadrzaj[i][j];
        break;
        case 6:
        inst.Wage = sadrzaj[i][j];
        break;
        case 7:	
        inst.Preferred_Foot = sadrzaj[i][j];
        break;
        case 8:
        inst.Position = sadrzaj[i][j];
        break;
        case 9:
        inst.Jersey_Number = sadrzaj[i][j];
        break;
        case 10:
        inst.Joined = sadrzaj[i][j];
        break;
        case 11:
        inst.Contract_Valid_Until = sadrzaj[i][j];
        break;
        case 12:
        inst.Height = sadrzaj[i][j];
        break;
        case 13:
        inst.Weight = sadrzaj[i][j];
        break;
        case 14:
        inst.BallControl = sadrzaj[i][j];
        break;
        case 15:
        inst.SprintSpeed = sadrzaj[i][j];
        break;
        case 16:
        inst.Agility = sadrzaj[i][j];
        break;
        case 17:
        inst.ShotPower = sadrzaj[i][j];
        break;
        case 18:
        inst.Jumping = sadrzaj[i][j];
        break;
        case 19:
        inst.Stamina = sadrzaj[i][j];
        break;
        case 20:
        inst.Strength = sadrzaj[i][j];
        break;
        case 21:
        inst.Release_Clause = sadrzaj[i][j];
        break;
        }
        }
    InstanceS.push_back(inst);
    }
}     
void NacrtajStablo(Node *node, int sirina)
{
    if (node==0) {
        cout<<setw(sirina)<<"*"<<endl;
    return;
    }
    NacrtajStablo(node->right, sirina+6);
        cout << setw(sirina) << node->key.substr(0, 4) <<"<"<<endl;
    
    NacrtajStablo(node->left, sirina+6);
}
int main()
{
    vector<Instanca> InstanceS;
    
    Ucitaj_u_vektor(InstanceS);
    InstanceS.pop_back();//Uklanja duplikat
    
    Node* Root = new Node(InstanceS.at(0));
    
    for (int i=1;i<InstanceS.size();i++) 
        Dodaj(Root, InstanceS.at(i));
    
    Node* AVL_Root = new Node(InstanceS.at(0));
    
    for (int i=1;i<InstanceS.size();i++){
        DodajAVL(AVL_Root, InstanceS.at(i));    
    } 

//ISPISI IZ STABALA
    cout<< "Preorder ispis uredenog binarnog stabla: \n";    
    Preorder(Root);
    cout<< "\nPreorder ispis AVL stabla: \n";
    Preorder(AVL_Root);  
    
    cout<< "\n\nSkica BST \n";
    NacrtajStablo(Root, 20);
    
    cout<<"\n\nSkica AVL \n";
    NacrtajStablo(AVL_Root, 20);
return 0;
}
