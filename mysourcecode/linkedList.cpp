2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
189
190
191
192
193
194
195
196
197
198
199
200
201
202
203
204
205
206
207
 
#include<stdio.h>
#include<stdlib.h>
 
struct LinkedList{
    int data;
    struct LinkedList *next;
 };
 
typedef struct LinkedList *node; //T? gi? dùng ki?u d? li?u LinkedList có th? thay b?ng node cho ng?n g?n
 
node CreateNode(int value){
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList)); // C?p phát vùng nh? dùng malloc()
    temp->next = NULL;// Cho next tr? t?i NULL
    temp->data = value; // Gán giá tr? cho Node
    return temp;//Tr? v? node m?i dã có giá tr?
}
 
node AddTail(node head, int value){
    node temp,p;// Khai báo 2 node t?m temp và p
    temp = CreateNode(value);//G?i hàm createNode d? kh?i t?o node temp có next tr? t?i NULL và giá tr? là value
    if(head == NULL){
        head = temp;     //N?u linked list dang tr?ng thì Node temp là head luôn
    }
    else{
        p  = head;// Kh?i t?o p tr? t?i head
        while(p->next != NULL){
            p = p->next;//Duy?t danh sách liên k?t d?n cu?i. Node cu?i là node có next = NULL
        }
        p->next = temp;//Gán next c?a th?ng cu?i = temp. Khi dó temp s? là th?ng cu?i(temp->next = NULL mà)
    }
    return head;
}
 
 
node AddHead(node head, int value){
    node temp = CreateNode(value); // Kh?i t?o node temp v?i data = value
    if(head == NULL){
        head = temp; // //N?u linked list dang tr?ng thì Node temp là head luôn
    }else{
        temp->next = head; // Tr? next c?a temp = head hi?n t?i
        head = temp; // Ð?i head hi?n t?i = temp(Vì temp bây gi? là head m?i mà)
    }
    return head;
}
 
node AddAt(node head, int value, int position){
    if(position == 0 || head == NULL){
        head = AddHead(head, value); // N?u v? trí chèn là 0, t?c là thêm vào d?u
    }else{
        // B?t d?u tìm v? trí c?n chèn. Ta s? dùng k d? d?m cho v? trí
        int k = 1;
        node p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            // N?u duy?t h?t danh sách lk r?i mà v?n chua d?n v? trí c?n chèn, ta s? m?c d?nh chèn cu?i
            // N?u b?n không mu?n chèn, hãy thông báo v? trí chèn không h?p l?
            head = AddTail(head, value);
            // printf("Vi tri chen vuot qua vi tri cuoi cung!\n");
        }else{
            node temp = CreateNode(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}
 
node DelHead(node head){
    if(head == NULL){
        printf("\nCha co gi de xoa het!");
    }else{
        head = head->next;
    }
    return head;
}
 
node DelTail(node head){
    if (head == NULL || head->next == NULL){
         return DelHead(head);
    }
    node p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next; // Cho next b?ng NULL
    // Ho?c vi?t p->next = NULL cung du?c
    return head;
}
 
node DelAt(node head, int position){
    if(position == 0 || head == NULL || head->next == NULL){
        head = DelHead(head); // N?u v? trí chèn là 0, t?c là thêm vào d?u
    }else{
        // B?t d?u tìm v? trí c?n chèn. Ta s? dùng k d? d?m cho v? trí
        int k = 1;
        node p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            // N?u duy?t h?t danh sách lk r?i mà v?n chua d?n v? trí c?n chèn, ta s? m?c d?nh xóa cu?i
            // N?u b?n không mu?n xóa, hãy thông báo v? trí xóa không h?p l?
            head = DelTail(head);
            // printf("Vi tri xoa vuot qua vi tri cuoi cung!\n");
        }else{
            p->next = p->next->next;
        }
    }
    return head;
}
 
int Get(node head, int index){
    int k = 0;
    node p = head;
    while(p != NULL && k != index){
        p = p->next;
    }
    return p->data;
}
 
int Search(node head, int value){
    int position = 0;
    for(node p = head; p != NULL; p = p->next){
        if(p->data == value){
            return position;
        }
        ++position;
    }
    return -1;
}
 
node DelByVal(node head, int value){
    int position = Search(head, value);
    while(position != -1){
        DelAt(head, position);
        position = Search(head, value);
    }
    return head;
}
 
void Traverser(node head){
    printf("\n");
    for(node p = head; p != NULL; p = p->next){
        printf("%5d", p->data);
    }
}
 
node InitHead(){
    node head;
    head = NULL;
    return head;
}
 
int Length(node head){
    int length = 0;
    for(node p = head; p != NULL; p = p->next){
        ++length;
    }
    return length;
}
 
node Input(){
    node head = InitHead();
    int n, value;
    do{
        printf("\nNhap so luong phan tu n = ");
        scanf("%d", &n);
    }while(n <= 0);
 
    for(int i = 0; i < n; ++i){
        printf("\nNhap gia tri can them: ");
        scanf("%d", &value);
        head = AddTail(head, value);
    }
    return head;
}
 
 
 
int main(){
    printf("\n==Tao 1 danh sach lien ket==");
    node head = Input();
    Traverser(head);
 
    printf("\n==Thu them 1 phan tu vao linked list==");
    head = AddAt(head, 100, 2);
    Traverser(head);
 
    printf("\n==Thu xoa 1 phan tu khoi linked list==");
    head = DelAt(head, 1);
    Traverser(head);
 
    printf("\n==Thu tim kiem 1 phan tu trong linked list==");
    int index = Search(head, 5);
    printf("\nTim thay tai chi so %d", index);
 
    printf("\nBan co the thu them nhe!");
 
}
