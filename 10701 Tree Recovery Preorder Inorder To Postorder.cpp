#include<stdio.h>

void constructPostorder(char *preorder, char *inorder){
	char pr1[60], in1[60];
	int len = 0;
	int i;

	//left subtree/child:

	for(i=0; inorder[i]; i++){
		// root of the subtree
		if(inorder[i] == preorder[0])
			break;

		in1[len] = inorder[i];

		// skipping the root in the preoder
		pr1[len] = preorder[i+1];

		in1[len+1] = '\0';
		pr1[len+1] = '\0';

		len++;
	}

	in1[len] = '\0';
	pr1[len] = '\0';

	// only one element in the left subtree
	if(len == 1)
		printf("%c",in1[0]);
	if(len > 1)
		constructPostorder(pr1, in1);

	//right subtree/child:

	// skipping the root
	i++;
	len = 0;
	for(; inorder[i]; i++, len++){
		in1[len] = inorder[i];
		pr1[len] = preorder[i];
		in1[len+1] = '\0';
		pr1[len+1] = '\0';
	}

	in1[len]='\0';
	pr1[len]='\0';

	if(len == 1)
		printf("%c",in1[0]);
	if(len > 1)
		constructPostorder(pr1, in1);

	//root/subroot
	printf("%c",preorder[0]);
}


// given preorder and inorder traversal, print the postorder traversal
int main(){
	char pre[60];
	char inor[60];

	int t;
	int l;
	scanf("%d",&t);

	for(int f=0; f<t; f++){
		scanf("%d%s%s", &l, &pre, &inor);
		constructPostorder(pre, inor);
		printf("\n");
	}

	return 0;
}
