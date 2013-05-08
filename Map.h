//project_2.h

#ifndef _Map_h_
#define _Map_h_

#include <iostream>
using namespace std;
#include <utility>

template <class K, class E>
class Map;

template <class K, class E>
class TreeNode;

template <class K, class E>
class MapIterator;

template <class K, class E>
class Map{
	
	public: 
		typedef MapIterator<K,E> iterator;
		Map(Map<K,E> &other);//copy constructor
		Map();
		~Map();
    	Map<K,E> &operator=( const Map<K,E> & shr );
		//MapIterator<K,E> &Map<K,E>::operator*(K key, E element);
		MapIterator<K,E> &operator*(const K key, const E element);//TODO
	
		void clear();
		int size();
		bool empty();
		int count(K &key);//TODO
		int erase(const K &z);
		int erase(iterator);//TODO
		//swap //TODO

		iterator find(const K &k);
		iterator begin();
		iterator end(); 					
	
	private:
		void clear(TreeNode<K,E> *leaf);
		TreeNode<K,E> *root;
		int Map_size;
};

template <class K, class E>
class TreeNode{	
	
	friend class Map<K,E>;
	friend class MapIterator<K,E>;

	private:	

		std::pair<K,E> pear;

		TreeNode <K,E> *parent;
		TreeNode <K,E> *left;
		TreeNode <K,E> *right;
};

template <class K, class E>
class MapIterator{

	friend class Map<K,E>;
	friend class TreeNode<K,E>;

	public:
		MapIterator() {current_node = NULL;}
		
		std::pair<K,E> &operator*() const {return current_node->pear;}

		bool operator!=(MapIterator &shr){
			return current_node != shr.current_node;}

		bool operator==(MapIterator &shr){
			return current_node == shr.current_node;}		
	
		MapIterator &operator++();

	private:
		MapIterator( TreeNode<K,E> *c) {current_node = c;}
		TreeNode<K,E> *current_node;
		std::pair<K,E> pear;
};

template<class K, class E> 
MapIterator<K,E> &Map<K,E>::operator*(const K key, const E element){//TODO

	bool inserted=false;

	MapIterator<K,E> itr;
	itr.current_node = root;
	TreeNode<K,E> *i_node;
	i_node = new TreeNode<K,E>;
	i_node->left = i_node->right = i_node->parent = NULL;
	(i_node->pear).first = key;
	(i_node->pear).second = element;

	while(!inserted){

		if(root == NULL){
			root = i_node;
			itr.current_node = root;
			Map_size++;
			inserted = true;
			return itr;
		}
		if(key < (*(itr)).first){//TODO:seg fault here
			if((itr.current_node->left) == NULL){
				i_node->left = i_node->right = NULL;
				i_node->parent = itr.current_node;
				(itr.current_node)->left = i_node;
				inserted = true;
			}else{
				itr.current_node = itr.current_node->left;
			}
		}
		if(key > (*(itr)).first){//TODO
			if(itr.current_node->right == NULL){
				i_node->left = i_node->right = NULL;
				i_node->parent = itr.current_node;
				(itr.current_node)->right = i_node;
				inserted = true;
            }else{
              	itr.current_node = itr.current_node->left;
            }
		}
		cout << "shit\n";
	}
	Map_size++;
	MapIterator<K,E> new_itr;
	new_itr.current_node = i_node;
	return new_itr;
}

template <class K, class E>
inline Map<K,E> & Map<K,E>::operator=( const Map<K,E> & shr ) {
    Map<K,E> copy_of_shr = shr;
    Map::swap(copy_of_shr.begin(), copy_of_shr.begin());//TODO
    return *this;
}

template <class K, class E>
MapIterator<K,E> Map<K,E>::begin(){
    
	MapIterator<K,E> itr;
	itr.current_node = root;

	while(itr.current_node->left != NULL){
		itr.current_node = itr.current_node->left;
	}

	return itr;

}

template <class K, class E>
MapIterator<K,E> Map<K,E>::end(){
    
	MapIterator<K,E> itr;
	itr.current_node = root;

	while(itr.current_node->right != NULL){
		itr.current_node = itr.current_node->right;
	}
	
	return itr;
}


template<class K, class E>
MapIterator<K,E> Map<K,E>::find(const K &k){
    for(typename Map<K,E>::iterator itr = begin(); itr != end(); ++itr){
		if((itr->first)== k){
			return itr;
		}
    }
}


template<class K, class E>
int Map<K,E>::erase(const K &z){

	TreeNode<K,E> *y = z.right;
	TreeNode<K,E> *q = z.parent;

	y->left = z.left;
	y->left.parent = y;
	z.left = NULL;
	y->parent = q;
	z.right = NULL;
	z.parent = NULL;
	
	if(z==q.left){
		q->left = y;
	}else{
		q->right = y;
	}	
	return 1;
}

//erase itr
template<class K, class E>
int Map<K,E>::erase(iterator itr){//TODO
	TreeNode<K,E> *y = itr.right;
	TreeNode<K,E> *q = itr.parent;

	y->left = itr.left;
	y->left.parent = y;
	itr.left = NULL;
	y->parent = q;
	itr.right = NULL;
	itr.parent = NULL;
	
	if(itr == q.left){
		q->left = y;
	}else{
		q->right = y;
	}	
	return 1;
}


template <class K, class E>//copy costructor
Map<K,E>::Map(const Map<K,E> &other){//TODO
//	some_node = new TreeNode<K,E>;
	new_map = new Map<K,E>;
	if(new_map.size() > other.size()){
		//increase other.size = new_map.size
		return 0;
	}
	if(new_map.size() < other.size()){
		//increase new_map.size = other.size
		return 0;
	}
	void traversal( ){//TODO
		new_map = new	
		if(other == NULL){
			traversal(other->other.left);
			traversal(other->other.right);
   	 		for(typename Map<K,E>::iterator itr = begin(); itr != end(); ++itr){
    			itr.other->current_node = itr.other->current_node;
			}
		}	
	}
}

template <class K, class E>
MapIterator<K,E> &MapIterator<K,E>::operator++(){
//tree successor
	MapIterator<K,E> itr;

	if (itr.current_node->right != NULL){	
		while(itr.current_node->left != NULL){
			itr.current_node = itr.current_node->left;
		}
		return itr;
	}
	while((itr.current_node->parent != NULL) && (itr.current_node == (itr.current_node->parent).right)){
		itr.current_node = itr.current_node->parent;
		itr.current_node->parent = current_node->parent->parent;
	}
	return itr;
}

template<class K, class E>
Map<K,E>::Map(){
	root = NULL;
	Map_size = 0;
}

template<class K, class E>
Map<K,E>::~Map(){
	clear();
}

template<class K, class E>
void Map<K,E>::clear(){
	Map::clear(root);
}

template<class K, class E>
void Map<K,E>::clear(TreeNode<K,E> *leaf){
	if(leaf != NULL){
		clear(leaf->left);
		clear(leaf->right);
		delete leaf;
	}
}

template<class K, class E>
bool Map<K,E>::empty(){
	return (root == NULL);	
}

template<class K, class E>
int Map<K,E>::size(){
	return Map_size;
}

template<class K, class E>
int Map<K,E>::count(K &key){//TODO

	int counter = 0;
	
	for(typename Map<K,E>::iterator itr = begin(); itr != end(); ++itr){
		if((itr->first) == key){
			counter++;
		}
	} 
	return counter;
}

//#include "Map.cpp"
#endif
