#define _CRT_SECURE_NO_WARNINGS 1
typedef struct Node {
	int val;
	struct Node *next;
}	Node;

// ��������м�λ��
Node * findMiddle(Node *head) {
	Node * fast = head;
	Node * slow = head;

	while (fast != NULL) {
		fast = fast->next;
		if (fast == NULL) {
			break;
		}
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

/*��ϰ��
˼·��
1��������������ĳ���
2���ó������߼��������Ȳ
3��ͬʱ�����ߣ�ʲôʱ������ָ��ָ��ͬһ������ˣ���ʾ�ҵ��������
*/
int getLength(struct ListNode *head) {
	int length = 0;
	for (struct ListNode *cur = head; cur != NULL; cur = cur->next) {
		length++;
	}

	return length;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	int lengthA = getLength(headA);
	int lengthB = getLength(headB);

	struct ListNode *longer = headA;
	struct ListNOde *shorter = headB;
	int diff = lengthA - lengthB;
	if (lengthB > lengthA) {
		longer = headB;
		shorter = headA;
		diff = lengthB - lengthA;
	}

	for (int i = 0; i < diff; i++) {
		longer = longer->next;
	}

	// ��ʹû�н���㣬��� longer �� shorter Ҳ��ͬʱ�ߵ� NULL
	// ����ѭ������������
	while (longer != shorter) {
		longer = longer->next;
		shorter = shorter->next;
	}

	return longer;
}

ListNode * deleteDuplication(ListNode *head) {
	if (head == NULL) {
		return NULL;
	}

	ListNode *prev = NULL;
	ListNode *p1 = head;
	ListNode *p2 = head->next;	// head һ�������� NULL

	while (p2 != NULL) {
		if (p1->val != p2->val) {
			prev = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else {
			while (p2 != NULL && p2->val == p1->val) {
				p2 = p2->next;
			}
			if (prev != NULL) {
				prev->next = p2;
			}
			else {
				head = p2;
			}
			p1 = p2;
			if (p2 != NULL) {
				p2 = p2->next;	// ��֤ p2 ����Ϊ ��
			}
		}
	}

	return head;
}

ListNode * reverseList(ListNode * head) {
	ListNode * r = NULL;
	ListNode * c = head;

	while (c != NULL) {
		ListNode *n = c->next;

		c->next = r;
		r = c;

		c = n;
	}

	return r;
}

ListNode * removeAll(ListNode *head, int val) {
	ListNode * p = head;	// ��Զ���� p �� c ��ǰ��
	ListNode * c = head->next;
	while (c != NULL) {
		if (c->val == val) {
			p->next = c->next;
		}
		else {
			p = c;
		}

		c = c->next;
	}

	if (head->val == val) {
		head = head->next;
	}

	return head;
}

bool hasCycle(struct ListNode *head) {
	if (head == NULL) {
		return NULL;
	}

	// ����жϴ���/����ָ����������
	struct ListNode *fast = head;
	struct ListNode *slow = head;

	do {
		fast = fast->next;
		if (fast == NULL) {
			return NULL;
		}
		fast = fast->next;
		if (fast == NULL) {
			return NULL;
		}
		slow = slow->next;
	} while (fast != slow);
	// fast �� slow ����������
	// ����ҵ�������ڵ�
	// һ���������� head
	// һ������������� slow
	// �������ָ������ˣ�������ڵ�
	struct ListNode *p1 = head;
	struct ListNode *p2 = slow;

	while (p1 != p2) {
		p1 = p1->next;
		p2 = p2->next;
	}

	return p1;
}


ListNode * copy(ListNode * head) {
	ListNode * result = NULL;
	ListNode * last = NULL;

	ListNode * cur = head;
	while (cur != NULL) {
		// 1. ���Ƶ���ֵ
		ListNode *node = (ListNode *)malloc(sizeof(ListNode));
		node->val = cur->val;

		if (result == NULL) {
			result = node;
		}
		else {
			last->next = node;
		}
		last = node;

		cur = cur->next;
	}

	last->next = NULL;

	return result;
}