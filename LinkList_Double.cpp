#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct DataST {
	string address;
	string houseowner;
	float price;
	int postcode;
};

struct NodeST {
	//区分头尾节点，数据单独放在一个结构体里;
	DataST* data;
	NodeST* pre;
	NodeST* nex;
};

class LinkList {
private:
	NodeST* head;
	NodeST* tail;
	int length;

public:
	LinkList();
	~LinkList();

	//CRUD;
	void Insert(string address, string houseowner, float price, int postcode);
	void Insert(DataST* data);
	void Retrieve();
	void Retrieve(int postcode);
	void Retrieve(string address);
	void Delete(string address);
	void DeleteForName(string houseowner);

	//Read & Write;
	void Read(string filedir);
	void Write(string filedir);
};

LinkList::LinkList() {
	cout << "LinkList start to be creating...It's first to build it." << endl;

	this->head = NULL;
	this->tail = NULL;
	this->length = 0;
}

LinkList::~LinkList() {
	cout << "LinkList has finished." << endl;
}

void LinkList::Insert(string address, string houseowner, float price, int postcode) {
	NodeST* node = new NodeST();
	node->data = new DataST();
	NodeST* nodeTmp = new NodeST();
	// NodeST* nodeTmp1 = new NodeST();
	// NodeST* nodeTmp2 = new NodeST();
	// NodeST* nodeTmp3 = new NodeST();

	node->data->address = address;
	node->data->houseowner = houseowner;
	node->data->price = price;
	node->data->postcode = postcode;

	//判断链表是否为空;
	//插入并排序，小到大；

	//空链表，则插入此值;
	if (!(this->head)) {
		node->pre = NULL;
		node->nex = NULL;
		head = tail = node;
		length++;

		return;
	}


	//比较插入;

	for (nodeTmp = head; nodeTmp != NULL; nodeTmp = nodeTmp->nex) {
		if (node->data->address < head->data->address) {
			head->pre = node;
			node->nex = head;
			head = node;
			return;
		}
		else if (node->data->address >= tail->data->address) {
			tail->nex = node;
			node->pre = tail;
			tail = node;
			return;
		}
		else if (node->data->address < nodeTmp->data->address) {
			node->nex = nodeTmp;
			node->pre = nodeTmp->pre;
			nodeTmp->pre->nex = node;
			nodeTmp->pre = node;
			return;
		}
		/* 		else {
					node->pre = nodeTmp;
					node->nex = nodeTmp->nex;
					nodeTmp->nex->pre = node;
					nodeTmp->nex = node;
				} */
	}


	/* 	//链表不为空，插入到尾巴;
		tail->nex = node;
		node->pre = tail;
		tail = node;
	 */

	 /* 	//根据ASCII码对地址进行排序;
		 //冒泡排序;
		 for (nodeTmp1 = head->nex; nodeTmp1->nex != NULL; nodeTmp1 = nodeTmp1->nex) {

			 for (nodeTmp2 = nodeTmp1->nex; nodeTmp2 != NULL; nodeTmp2 = nodeTmp2->nex) {

				 if (nodeTmp2->data->address < nodeTmp1->data->address) {
					 nodeTmp3 = nodeTmp1;
					 nodeTmp1 = nodeTmp2;
					 nodeTmp2 = nodeTmp3;
				 }
			 }
		 } */




	return;
}

void LinkList::Insert(DataST* data) {
	NodeST* node = new NodeST();
	node->data = data;
	NodeST* nodeTmp1 = new NodeST();
	NodeST* nodeTmp2 = new NodeST();
	NodeST* nodeTmp3 = new NodeST();

	//空链表，则插入此值;
	if (!(this->head)) {
		node->pre = NULL;
		node->nex = NULL;
		head = tail = node;
		length++;

		return;
	}


	//链表不为空，插入到尾巴;
	tail->nex = node;
	node->pre = tail;
	tail = node;


	//根据ASCII码对地址进行排序;
	//冒泡排序;
	for (nodeTmp1 = head->nex; nodeTmp1->nex != NULL; nodeTmp1 = nodeTmp1->nex) {

		for (nodeTmp2 = nodeTmp1->nex; nodeTmp2 != NULL; nodeTmp2 = nodeTmp2->nex) {

			if (nodeTmp2->data->address < nodeTmp1->data->address) {
				nodeTmp3 = nodeTmp1;
				nodeTmp1 = nodeTmp2;
				nodeTmp2 = nodeTmp3;
			}
		}
	}


	return;
}

void LinkList::Retrieve() {
	NodeST* node = head;
	int sequence = 1;

	cout << "Print all LinkList" << endl;
	while (node) {
		cout << "The Address is:" << node->data->address << endl;
		cout << "The House Owner is:" << node->data->houseowner << endl;
		cout << "The House PostCode is:" << node->data->postcode << endl;
		cout << "The data's sequence in List is:" << sequence << endl;

		node = node->nex;
		sequence++;
	}

	cout << "Print finished." << endl;
}

void LinkList::Retrieve(int postcode) {
	NodeST* node = head;
	int sequence = 1;

	while (node) {
		//default is searching by Address. 
		cout << "Find them. PostCode would be shown:" << endl;

		if (node->data->postcode == postcode) {
			cout << "The Address is:" << node->data->address << endl;
			cout << "The House Owner is:" << node->data->houseowner << endl;
			cout << "The House PostCode is:" << node->data->postcode << endl;
			cout << "The data's sequence in List is:" << sequence << endl;
		}
		node = node->nex;
		sequence++;
	}

	cout << "search finished. The last pointer is:" << node << endl;
}

void LinkList::Retrieve(string address) {
	NodeST* node = head;
	int sequence = 1;

	while (node) {
		//searching by Address. 
		cout << "Find them. Address would be shown:" << endl;

		if (node->data->address == address) {
			cout << "The Address is:" << node->data->address << endl;
			cout << "The House Owner is:" << node->data->houseowner << endl;
			cout << "The House PostCode is:" << node->data->postcode << endl;
			cout << "The data's sequence in List is:" << sequence << endl;
		}
		node = node->nex;
		sequence++;
	}
	cout << "search finished. The last pointer is:" << node << endl;

}

void LinkList::Delete(string address) {
	NodeST* node = head;

	while (node) {
		cout << "Find them. Address would be deleted:" << endl;
		if (node->data->address != address) {
			node = node->nex;
			continue;
		}
		else if (node->pre == NULL) {
			head = node->nex;
			break;
		}

		node->pre->nex = node->nex;
		node->nex->pre = node->pre;
		break;
	}

	delete(node);
}

void LinkList::DeleteForName(string houseowner) {
	NodeST* node = head;
	NodeST* nodeTmp;

	while (node) {
		cout << "Find them. houseowner would be deleted:" << endl;

		if (node->data->houseowner != houseowner) {
			node = node->nex;
			continue;
		}
		else if (node->pre == NULL) {
			node = node->nex;
			nodeTmp = head;
			head = node;
			delete(nodeTmp);
			continue;
		}

		nodeTmp = node;
		node = node->nex;
		nodeTmp->pre->nex = node;
		node->pre = nodeTmp->pre;
		delete(nodeTmp);
	}
}

void LinkList::Read(string filedir) {

	cout << "start." << endl;
	ifstream infile;
	infile.open(filedir);
	cout << "Open the file." << endl;

	string tmp;
	int count = 0;

	string address;
	string houseowner;
	float price;
	int postcode;


	if (!infile) {
		cout << "Files error." << endl;
		return;
	}

	cout << endl << "Reading...." << endl;

	while (getline(infile, tmp, ',')) {

		count++;
		switch (count % 4) {
		case 0: cout << "The forth parameter:" << tmp; postcode = stoi(tmp); break;
		case 1: cout << "The first parameter:" << tmp; address = tmp; break;
		case 2: cout << "The second parameter:" << tmp; houseowner = tmp; break;
		case 3: cout << "The third parameter:" << tmp; price = stof(tmp); break;

		default: cout << "Calculation error." << endl;
		}

		// if (!(count % 4))	Insert(data);

		if (!(count % 4)) Insert(address, houseowner, price, postcode);
	}

	/* 	node = head;

		if (node->data->address == "address" || node->data->houseowner == "houseowner") {
			node = node->nex;
			node->pre = NULL;

			delete(head);
			head = node;
		} */

	cout << "Have been read all data." << endl;

	infile.close();
}

void LinkList::Write(string filedir) {
	ofstream outfile;
	outfile.open(filedir, ios::app | ios::out | ios::ate);
	NodeST* node = head;

	if (!outfile) outfile << "address,houseowner,price,postcode" << endl;

	while (node) {
		outfile << node->data->address << ",";
		outfile << node->data->houseowner << ",";
		outfile << node->data->price << ",";
		outfile << node->data->postcode << endl;

		node = node->nex;
	}

	cout << "recreated success." << endl;

	outfile.close();
}

int main() {

	LinkList doubleList;
	char status;
	int status1;
	DataST* data = new DataST();
	string judge;

	string address;
	string houseowner;
	float price;
	int postcode;

	while (1) {
		cout << "Welcome to the manage tool." << endl;
		cout << "Please make your choose(Input number):" << endl;

		cout << "1.Insert new data." << endl;
		cout << "2.Retrieve all data." << endl;
		cout << "3.Delete the data." << endl;
		cout << "4.Read all data from file." << endl;
		cout << "5.Output all data to file." << endl;
		cout << "6.Print all LinkList" << endl;
		cout << "7.Exit" << endl;
		cin.clear();
		cin >> status;
		//将char类型变成ascii码，可以进行比较；
		status1 = status;
		while (status1 < 49 || status1 > 55 || status1 == NULL) {
			cout << "invalid input number, please try again." << endl;
			cin >> status;
			status1 = status;
		}

		cout << "You make choice:" << status1 - 48 << endl;
		switch (status1 - 48) {
		case 1:
			cout << "Input address,houseowner,price,postcode separately:";
			//cin >> data->address >> data->houseowner >> data->price >> data->postcode;
			//doubleList.Insert(data);

			cout << "Input address:";
			cin >> address;

			cout << "Input houseowner:";
			cin >> houseowner;

			cout << "Input price:";
			cin >> price;

			cout << "Input postcode:";
			cin >> postcode;

			doubleList.Insert(address, houseowner, price, postcode);

			cout << "return to main menu." << endl;
			break;
		case 2:
			cout << "Retrieve all data. Please input postcode or address to chose one way." << endl;
			cin >> judge;
			if (judge == "postcode" || judge == "Postcode") {
				cout << "Input postcode number:";
				cin >> postcode;
				doubleList.Retrieve(postcode);
			}
			else if (judge == "address" || judge == "Address") {
				cout << "Input address:";
				cin >> address;
				doubleList.Retrieve(address);
			}
			cout << "return to main menu." << endl;
			break;
		case 3:
			cout << "Delete the data. Chose one way to delete the data:address or houseowner." << endl;
			cin >> judge;
			if (judge == "address" || judge == "Address") {
				cout << "Input address:";
				cin >> address;
				doubleList.Delete(address);
			}
			else if (judge == "houseowner" || judge == "houseowner") {
				cout << "Input houseowner:";
				cin >> houseowner;
				doubleList.DeleteForName(houseowner);
			}
			cout << "return to main menu." << endl;
			break;
		case 4:
			cout << "Read all data from the file." << endl;
			doubleList.Read("a.data");
			cout << "return to main menu." << endl;
			break;
		case 5:
			cout << "5.Output all data to file." << endl;
			doubleList.Write("a.data");
			cout << "5.Output all data to file." << endl;
			break;
		case 6:
			cout << "Searching..." << endl;
			doubleList.Retrieve();
			break;
		default:
			cout << "Exit this program.";
			exit(0);
		}
	}


}
