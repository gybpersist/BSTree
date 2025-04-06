#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
���BST���������������Զ��������нڵ����ɾ������˫��ѭ������ʵ�֣�ÿ���ڵ�
����Ҫ2��ָ�룬�ֱ�ָ��ýڵ����������lchild������������rchild��
����1���������нڵ������
����2: ��������Ҷ�ӽڵ����������Ϊ0��
����3: ��������������
*/

//���ͱ��� �ڵ���Ч��ֵ
typedef int dataType_t;
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
//����BST���Ľڵ� BST�������Խڵ����������Ӧ������ͬ��
typedef struct BSTreeNode {
    dataType_t Keyval;                 //BST���ļ�ֵ
    struct BSTreeNode *lchild;      //BST������������ָ����
    struct BSTreeNode *rchild;      //BST������������ָ����
} BSTNode_t;
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
//1 ����һ�������ڵ��BST������BST���ĸ��ڵ���г�ʼ��
BSTNode_t* BSTree_Create(dataType_t Keyval)
{
    //1.1 ����һ�����ڵ㲢�����ڵ������ڴ�
    BSTNode_t *Root = (BSTNode_t*)calloc(1,sizeof (BSTNode_t));
    if(Root == NULL)
    {
        perror("calloc memory for Root is Failed!\n");
        exit(-1);       //�˳�����
    }

    //1.2 �Ը��ڵ���г�ʼ��
    Root->lchild = NULL;
    Root->Keyval = Keyval;
    Root->rchild = NULL;

    //1.3 ��ͷ�ڵ�ص�ַ����
    return Root;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
//2 �����µĽڵ㣬�����½ڵ���г�ʼ���������� ָ����
BSTNode_t *BSTree_NewNode(dataType_t Keyval)
{
    //2.1 ����һ���½ڵ㲢���½ڵ������ڴ�
    BSTNode_t *NewNode = (BSTNode_t *) calloc(1, sizeof(BSTNode_t));
    if(NewNode == NULL)
    {
        perror("calloc memory for NewNode is Failed!\n");
        return NULL;
    }

    //2.2 ���½ڵ���г�ʼ���������� ָ����2����
    NewNode->lchild = NULL;
    NewNode->Keyval = Keyval;
    NewNode->rchild = NULL;

    //2.3 ���½ڵ�ص�ַ����
    return NewNode;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
//3 ��BST���м���ڵ�  ���ڵ����������ֵ�ȸ��ڵ�ļ�ֵС�����ڵ����������ֵ�ȸ��ڵ�ļ�ֵ�� ���ֵݹ�˼��
bool BSTree_InsertNode(BSTNode_t *Root,dataType_t Keyval)
{
    //3.0 ������ڵ��ַ��ʧ���Ը��ڵ��ַ���б���
    BSTNode_t *Proot = Root;

    //3.1 �����½ڵ㲢���½ڵ���г�ʼ��
    BSTNode_t *NewNode = BSTree_NewNode(Keyval);

    //3.2 ��ʱ������ǰBST���Ƿ�Ϊ���������� or �ǿ�����
    //Ϊ����
    if(Root == NULL)
    {
        //���½ڵ���ΪBST���ĸ��ڵ�
        Root = NewNode;
    }
    else  //Ϊ�ǿ���,2���������ֵ ����/������ ���ڵ㣩
    {
        while(Proot)
        {
            //�½ڵ�ļ�ֵ�͵�ǰ�µĸ��ڵ�ļ�ֵ�Ƚ�,��� ֱ���˳�
            if(NewNode->Keyval == Proot->Keyval)
            {
                printf("Can Not Insert,......\n");
                return false;
            }
            else  //�½ڵ�ļ�ֵ�͵�ǰ�µĸ��ڵ�ļ�ֵ�Ƚ�,����� ��������
            {
                //�½ڵ�ļ�ֵ�͵�ǰ�µĸ��ڵ�ļ�ֵ�Ƚ�,С�� �Ѹ��ڵ����������Ϊ�µĸ�
                if(NewNode->Keyval < Proot->Keyval)
                {
                    if(Proot->lchild == NULL)
                    {
                        Proot->lchild = NewNode;
                        break;
                    }
                    Proot = Proot->lchild;
                }
                else  //�½ڵ�ļ�ֵ�͵�ǰ�µĸ��ڵ�ļ�ֵ�Ƚ�,���� �Ѹ��ڵ����������Ϊ�µĸ�
                {
                    if(Proot->rchild == NULL)
                    {
                        Proot->rchild = NewNode;
                        break;
                    }
                    Proot = Proot->rchild;
                }
            }
        }
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
// ǰ����� ������ ���ֵݹ�˼��
bool BSTree_PreOrder(BSTNode_t *Root)
{
    //ʹ�õݹ麯����������д����ֹ����
    if(Root == NULL)
    {
        return false;
    }
    
    //��������ڵ�ļ�ֵ
    printf("%d  ",Root->Keyval);
    
    //��������ڵ��������
    BSTree_PreOrder(Root->lchild);
    //��������ڵ��������
    BSTree_PreOrder(Root->rchild);

    return true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
// ������� ����� ���ֵݹ�˼��
bool BSTree_InOrder(BSTNode_t *Root)
{
    //ʹ�õݹ麯����������д����ֹ����
    if(Root == NULL)
    {
        return false;
    }
    //��������ڵ��������
    BSTree_InOrder(Root->lchild);

    //��������ڵ�ļ�ֵ
    printf("%d  ",Root->Keyval);

    //��������ڵ��������
    BSTree_InOrder(Root->rchild);

    return true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
// ������� ���Ҹ� ���ֵݹ�˼��
bool BSTree_PostOrder(BSTNode_t *Root)
{
    //ʹ�õݹ麯����������д����ֹ����
    if(Root == NULL)
    {
        return false;
    }
    //��������ڵ��������
    BSTree_PostOrder(Root->lchild);

    //��������ڵ��������
    BSTree_PostOrder(Root->rchild);

    //��������ڵ�ļ�ֵ
    printf("%d  ",Root->Keyval);

    return true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
// ����1���������нڵ������ �ɲ��õݹ�
int BSTree_CountNode(BSTNode_t *Root)
{
    int n1 = 0;     //��¼�������Ľڵ���
    int n2 = 0;     //��¼�������Ľڵ���

    //ʹ�õݹ麯����������д����ֹ����
    if(Root == NULL)
    {
        return 0;
    }

    //������ú����������ڵ�����
    n1 = BSTree_CountNode(Root->lchild);
    n2 = BSTree_CountNode(Root->rchild);

    return n1 + n2 +1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
// ����2����������Ҷ�ӽڵ������ �ɲ��õݹ�
int BSTree_CountLeafNode(BSTNode_t *Root)
{
    int n1 = 0;     //��¼�������Ľڵ���
    int n2 = 0;     //��¼�������Ľڵ���

    //ʹ�õݹ麯����������д����ֹ����
    if (Root == NULL)
    {
        return 0;
    }

    //˵��ֻ��һ�����ڵ�
    if(Root->lchild == NULL && Root->rchild == NULL)
    {
        return 1;
    }

    //˵��������
    n1 = BSTree_CountLeafNode(Root->lchild);
    n2 = BSTree_CountLeafNode(Root->rchild);

    return n1 + n2;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
// ����3���������������� �ɲ��õݹ�
int BSTree_GetDepth(BSTNode_t *Root)
{
    int n1 = 0;     //��¼�����������
    int n2 = 0;     //��¼�����������

    //ʹ�õݹ麯����������д����ֹ����
    if (Root == NULL)
    {
        return 0;
    }

//    //�������������
//    //˵��ֻ��һ�����ڵ�
//    if(Root->lchild == NULL && Root->rchild == NULL)
//    {
//        return 1;
//    }

    //˵�������� ��������������� �� ��������������� ��� �Ƚ�������ټ�һ
    n1 = BSTree_GetDepth(Root->lchild);
    n2 = BSTree_GetDepth(Root->rchild);

    return ( (n1>n2)?n1:n2 ) + 1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    //1 ����һ�������ڵ��BST��
    BSTNode_t *Root = BSTree_Create(10);

    //2 ��BST�������½ڵ�
    BSTree_InsertNode(Root,5);
    BSTree_InsertNode(Root,20);
    BSTree_InsertNode(Root,7);
    BSTree_InsertNode(Root,12);
    BSTree_InsertNode(Root,8);
    BSTree_InsertNode(Root,3);
    BSTree_InsertNode(Root,25);
    BSTree_InsertNode(Root,26);

//                     10
//            5                   20
//        3       7           12      25
//                    8                     26

    printf("ǰ�����Ϊ:\n");
    BSTree_PreOrder(Root);

    printf("\n�������Ϊ:\n");
    BSTree_InOrder(Root);

    printf("\n�������Ϊ:\n");
    BSTree_PostOrder(Root);

    printf("\n�ܽڵ�����%d",BSTree_CountNode(Root));

    printf("\n����Ҷ�ӽڵ�����%d",BSTree_CountLeafNode(Root));

    printf("\n����������ȣ�%d",BSTree_GetDepth(Root));

    return 0;
}
