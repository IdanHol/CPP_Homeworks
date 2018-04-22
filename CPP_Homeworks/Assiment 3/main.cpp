#include "Member.h"
using namespace std;

Member avi, beni, chana;

void test1() {
	Member dana;
    
	chana.follow(dana);
	dana.follow(avi);
	cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 1
	cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 1 0
	cout << "  " << Member::count() << endl; // 4
}

void test2(){

    /**
     * https://github.com/xGreenbean/CS-2018-CPP/blob/master/HW_3/main.cpp
     * This test is copied
     */


        cout<< "test2" << endl;
        Member moshe,ravid;
        moshe.follow(chana);
        ravid.follow(avi);
        avi.follow(chana);
        chana.follow(ravid);
    
        cout << "  " << moshe.numFollowers() << " " <<  moshe.numFollowing() << endl; // 0 1
        cout << "  " << ravid.numFollowers() << " " <<  ravid.numFollowing() << endl; // 1 1
        cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 2 1
        cout << "  " << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 1 1

        cout<<"end -test2"<<endl;
}

void test3() {
    cout << "test3" << endl;
    Member idan, gilad;
    idan.follow(beni);
    beni.follow(gilad);
    gilad.follow(idan);
    idan.follow(chana);
    chana.follow(gilad);

    cout << "  " << idan.numFollowers() << " " <<  idan.numFollowing() << endl; // 1 2
    cout << "  " << gilad.numFollowers() << " " <<  gilad.numFollowing() << endl; // 2 1
    cout << "  " << beni.numFollowers() << " " <<  beni.numFollowing() << endl; // 1 1
    cout << "  " << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 2 1

    cout<<"end -test3"<<endl;

}
int main() {
		cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	avi.follow(beni);
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	cout << beni.numFollowers() << " " << beni.numFollowing() << endl; // 1 0
	cout << Member::count() << endl; // 3
	cout << endl;

	avi.follow(beni); // duplicate follow has no effect
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	avi.unfollow(beni);	
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	cout << endl;

	cout << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 0
	test1();
    test2();
    test3();
	cout << chana.numFollowers() << " " <<  chana.numFollowing() << endl; // 0 0
	cout << avi.numFollowers() << " " <<  avi.numFollowing() << endl; // 0 0
	cout << Member::count() << endl; // 3
    cout << &avi << endl;
    avi.~Member();
    cout<<&avi<<endl;
    cout << Member::count() << endl;
}