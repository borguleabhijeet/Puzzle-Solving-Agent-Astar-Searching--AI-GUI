
#ifndef SOURCE_H
#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#include<queue>
#include<unordered_set>

#include "afxdialogex.h"
#define MX(a,b) ((a) > (b) ? (a) : (b))
using namespace std;
class Node
{
	//
public:
	vector<Node>parent;
	vector<Node>children;
     int cost;
     int estimatedCostToGoal;
     int totalCost;
     int depth;
	 bool visited;
	 int getDepth() {  return depth; }
	 void setDepth(int depth) { this->depth = depth;}
	  bool  isVisited(void) { return this->visited; }
	  int getTotalCost() {return totalCost;}
	  void setTotalCost(int totalCost) { this->totalCost = totalCost; }
	  string state;
    int x;
	int y;
      void setTotalCost(int cost, int estimatedCost) 
	  {
        totalCost = cost + estimatedCost;
    }

     int getEstimatedCostToGoal() 
	 {
        return estimatedCostToGoal;
    }

      void setEstimatedCostToGoal(int estimatedCostToGoal)
	  {
        this->estimatedCostToGoal = estimatedCostToGoal;
    }

      int getCost() {
        return cost;
    }
	void setCost(int cost) {
        this->cost = cost;
    }
      // Constructor
      Node(string state){ 
		   this-> cost=0;
     this-> estimatedCostToGoal=0;
     this-> totalCost=0;
     this-> depth=0;
	 this-> visited=0;
	 this->state=state;
	  }

    // Properties
      string getState() {
        return state;
    }

      vector<Node> getChildren() {
        return children;
    }

    //   interface
      void addChild(Node child) {
        children.push_back(child);
    }

	      Node getParent()
		  {
			  return parent[0];
		 }

     void setParent(Node  pr)
	 {
		 this->parent.push_back(pr);
    }

	  
};
inline vector<string>getSuccessors(string str)
{
	string tmp;
	vector<string>moves;	
	switch(str.find("0"))
	{
		
		case 0:{
								string temp=str;
								string st;
								 st=temp.at(1); temp.at(1) = temp.at(0); temp.at(0)=st.at(0); moves.push_back(temp);temp=str;				  
								 st=temp.at(3); temp.at(3) = temp.at(0); temp.at(0)=st.at(0); moves.push_back(temp);temp=str; 
								 break;
						}
		case 1:
						{
								string temp=str;
								string st;
								 st=temp.at(0); temp.at(0) = temp.at(1); temp.at(1)=st.at(0); moves.push_back(temp);temp=str;				  
								 st=temp.at(2); temp.at(2) = temp.at(1); temp.at(1)=st.at(0); moves.push_back(temp);temp=str;
								 st=temp.at(4); temp.at(4) = temp.at(1); temp.at(1)=st.at(0); moves.push_back(temp);temp=str; 
								 break;
						}
        case 2:	{
								string temp=str;
								string st;
								 st=temp.at(1); temp.at(1) = temp.at(2); temp.at(2)=st.at(0); moves.push_back(temp);temp=str;				  
								 st=temp.at(5); temp.at(5) = temp.at(2); temp.at(2)=st.at(0); moves.push_back(temp);temp=str; 
								 break;
								
						}
	    case 3:{
								string temp=str;
								string st;
								 st=temp.at(0); temp.at(0) = temp.at(3); temp.at(3)=st.at(0); moves.push_back(temp);temp=str;				  
								 st=temp.at(4); temp.at(4) = temp.at(3); temp.at(3)=st.at(0); moves.push_back(temp);temp=str;
								 st=temp.at(6); temp.at(6) = temp.at(3); temp.at(3)=st.at(0); moves.push_back(temp);temp=str; 
								 break;
								
						}
		case 4:{		string temp=str;
								string st;
								 st=temp.at(1); temp.at(1) = temp.at(4); temp.at(4)=st.at(0); moves.push_back(temp);temp=str;				  
								  st=temp.at(3); temp.at(3) = temp.at(4); temp.at(4)=st.at(0); moves.push_back(temp);temp=str;
								   st=temp.at(5); temp.at(5) = temp.at(4); temp.at(4)=st.at(0); moves.push_back(temp);temp=str;
								  st=temp.at(7); temp.at(7) = temp.at(4); temp.at(4)=st.at(0); moves.push_back(temp);temp=str; break;
						}
		case 5:{
									string temp=str;
								string st;	 
								 st=temp.at(2); temp.at(2) = temp.at(5); temp.at(5)=st.at(0); moves.push_back(temp);temp=str;				  
						  		st=temp.at(4); temp.at(4) = temp.at(5); temp.at(5)=st.at(0); moves.push_back(temp);temp=str;					
						  	  st=temp.at(8); temp.at(8) = temp.at(5); temp.at(5)=st.at(0); moves.push_back(temp);temp=str;
								  break;
			}
		case 6:{	string temp;
			 temp=str;
				string st;
				 st=temp.at(3); temp.at(3) = temp.at(6); temp.at(6)=st.at(0); moves.push_back(temp); temp=str;			 
			  	 st=temp.at(7); temp.at(7) = temp.at(6); temp.at(6)=st.at(0); moves.push_back(temp); temp=str;
				 break;
		}
		case 7:{	string temp=str;
				string st;
						  
				  st=temp.at(4); temp.at(4) = temp.at(7); temp.at(7)=st.at(0); moves.push_back(temp);temp=str;
				  	 st=temp.at(6); temp.at(6) = temp.at(7); temp.at(7)=st.at(0); moves.push_back(temp);temp=str;	
				  st=temp.at(8); temp.at(8) = temp.at(7); temp.at(7)=st.at(0); moves.push_back(temp);temp=str;
				  break;
				}
	  case 8: {
				string temp;
			 temp=str;
				string st;
				
			  	 st=temp.at(5); temp.at(5) = temp.at(8); temp.at(8)=st.at(0); moves.push_back(temp); temp=str;
				  st=temp.at(7); temp.at(7) = temp.at(8); temp.at(8)=st.at(0); moves.push_back(temp);temp=str;  
				  break;

			
			     }
		
			
				
	}
return moves;
}
inline int heuristicTwo(string currentState, string goalSate) 
{
        int difference = 0;
        for (int i = 0; i<currentState.length(); i++)
           {
			   for (int j = 0; j<goalSate.length(); j++)
			   {
				   
				   if (currentState.at(i) == goalSate.at(j))
                      {
						  difference = difference + ((abs(i % 3 - j % 3)) + abs(i / 3 + j / 3));
				   }
			   }
		}

		
		
        return difference;
    }
inline bool compares(Node  x,Node  y)
		 {
	    if (x.getTotalCost() <=y.getTotalCost()) {
           	return 0;	
        }
        if (x.getTotalCost()> y.getTotalCost()) {
            return 1;
        }
       
		
	}
class Search
{
public:
	void Astar(string goalstate,string problemstate,CMFCButton & panel0,CMFCButton & panel1,CMFCButton & panel2,CMFCButton & panel3,CMFCButton & panel4,CMFCButton & panel5,CMFCButton & panel6,CMFCButton & panel7,CMFCButton & panel8,CMFCButton & stateinfo);
	void Rbfs(string goalstate,string problemstate);
	Node Rbfsiter(Node currentnode,int flimit,string Goalstate);	
};
	std::priority_queue<Node, std::vector<Node>, bool (*)(Node, Node)> PriorityQueue(compares);		
//	 std::sort(node.begin(), node.end(), [](Node & n1, Node & n2) { return (n1.getTotalCost() < n2.getTotalCost()); });
	std::unordered_set<string> stateSets1;
Node  Search::Rbfsiter(Node currentnode,int flimit,string Goalstate)
{

		if(!(currentnode.getState().compare(Goalstate)))
			return currentnode;
		stateSets1.insert(currentnode.getState());
	vector<string> nodeSuccessors = getSuccessors(currentnode.getState());
		if(nodeSuccessors.size()<1)
			return currentnode;		
		vector<Node>node;

		 for (int j=0;j<nodeSuccessors.size();j++)
		{
		    auto a = stateSets1.find(nodeSuccessors[j]);
				   if(a != stateSets1.end()) 
					continue;
				Node * child =  new Node(nodeSuccessors[j]);
				currentnode.addChild(*child);
				 child->setParent(currentnode);
				 int g=currentnode.getTotalCost()+(int)(child->getState().at(child->getParent().getState().find('0'))-'0');
				 int h=heuristicTwo(child->getState(),Goalstate);//+rand() % 100;// we use this random adding to see the perormance of RBFS
				 child->setTotalCost(MX(g+h,child->getTotalCost()));
				PriorityQueue.push(*child);
		 } 
	
		 while(1)
		 {
		 Node best= PriorityQueue.top();

		if(best.getTotalCost()>flimit)
		{ 
		return best;
	
		}

		PriorityQueue.pop();

		Node Alternative=PriorityQueue.top();
		
		Node result=Rbfsiter(best, min<long>(flimit,Alternative.getTotalCost()),Goalstate);
		if(!(result.getState().compare(Goalstate)))
			return result;
		 }
}

void Search::Rbfs(string goalstate,string problemstate)
{
	Node * root=new Node(problemstate);
	Node currentnode=*root;
		clock_t tStart = clock();
		currentnode= Rbfsiter(currentnode,INFINITE,goalstate);
	
	vector<Node>solutionStack;
       solutionStack.push_back(currentnode);
	  while(currentnode.getState().compare(root->getState()))
		{
            solutionStack.push_back(currentnode.getParent());
            currentnode = currentnode.getParent();
		
        }
		for(int xx=solutionStack.size();xx>0;xx--)
		{
			
					int cnt=0;
							for(int m=0;m<3;m++)
							{
								for(int n=0;n<3;n++)
								{
									cout<<solutionStack[xx-1].getState().at(cnt);cnt++;
								}
								cout<<endl;
							}
					cout<<endl;
		}
	
		  printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}
void Search::Astar(string goalSate,string problemstate,CMFCButton & panel0,CMFCButton & panel1,CMFCButton & panel2,CMFCButton & panel3,CMFCButton & panel4,CMFCButton & panel5,CMFCButton & panel6,CMFCButton & panel7,CMFCButton & panel8,CMFCButton & stateinfo)
{

		int cnt,time=0;			
					
					std::unordered_set<string> stateSets;

	std::priority_queue<Node, std::vector<Node>, bool (*)(Node, Node)> nodePriorityQueue(compares);
	  
  std::priority_queue<Node*>successorsQueue ;
	  Node * root=new Node(problemstate);
	    Node Cnode=*root;
			  
	clock_t tStart = clock();
	
	   CMy8puzzleDlg val;
		while(Cnode.getState().compare(goalSate))
		{
			stateSets.insert(Cnode.getState());
			  vector<string> nodeSuccessors = getSuccessors(Cnode.getState());
			  for (int j=0;j<nodeSuccessors.size();j++)
			  {
				    auto a = stateSets.find(nodeSuccessors[j]);
				   if(a != stateSets.end()) 
						 continue;

				   stateSets.insert(nodeSuccessors[j]);
				     Node * child =  new Node(nodeSuccessors[j]);
				    Cnode.addChild(*child);
					 child->setParent(Cnode);				 
					 int g=Cnode.getTotalCost()+(int)(child->getState().at(child->getParent().getState().find('0'))-'0');
					 int h=heuristicTwo(child->getState(),goalSate) ;
					 child->setTotalCost(g,h);
					nodePriorityQueue.push(*child);
			delete child;
						//child->setTotalCost
			  }

			vector<string>tmp(stateSets.begin(), stateSets.end());
			 Cnode=nodePriorityQueue.top();
			 string s="States Explored:"+Cnode.getState();			 
			 stateinfo.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
		//	 GetDlgItem()->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
		//	item.GetDlgItem(1061)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
	 	  	nodePriorityQueue.pop();
			
		time++;
		}

		
	vector<Node>solutionStack;
       solutionStack.push_back(Cnode);
	  while(Cnode.getState().compare(root->getState()))
		{
            solutionStack.push_back(Cnode.getParent());
            Cnode = Cnode.getParent();
		
        }
	 
		for(int xx=solutionStack.size();xx>0;xx--)
		{
			
					int cnt=0;
							for(int m=0;m<3;m++)
							{
								for(int n=0;n<3;n++)
								{cout<<solutionStack[xx-1].getState().at(cnt);cnt++;
									
								  


							//	val.check(0,solutionStack[xx-1].getState().find('0'));
									string s;
									s=(1, solutionStack[xx-1].getState().at(0));
									panel8.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
									s=(1, solutionStack[xx-1].getState().at(1));
									panel1.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
										s=(1, solutionStack[xx-1].getState().at(2));
									panel2.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
										s=(1, solutionStack[xx-1].getState().at(3));
									panel3.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
										s=(1, solutionStack[xx-1].getState().at(4));
									panel4.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
										s=(1, solutionStack[xx-1].getState().at(5));
									panel5.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
										s=(1, solutionStack[xx-1].getState().at(6));
									panel6.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
										s=(1, solutionStack[xx-1].getState().at(7));
									panel7.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
										s=(1, solutionStack[xx-1].getState().at(8));
									panel0.SetWindowTextW((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str());
									
									val.action_take(solutionStack[xx-1].getState().find('0'),panel0,panel1,panel2,panel3,panel4,panel5,panel6,panel7,panel8);
									Sleep(100);
								/*	GetDlgItem()->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
									s=(1, given.at(1));
									GetDlgItem(IDC_BUTTON1)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
									s=(1, given.at(2));
									GetDlgItem(IDC_BUTTON2)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
									s=(1, given.at(3));
									GetDlgItem(IDC_BUTTON3)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
									s=(1, given.at(4));
									GetDlgItem(IDC_BUTTON4)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
									s=(1, given.at(5));
									GetDlgItem(IDC_BUTTON5)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
									s=(1, given.at(6));
									GetDlgItem(IDC_BUTTON6)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
									s=(1, given.at(7));
									GetDlgItem(IDC_BUTTON7)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
									s=(1, given.at(8));
									GetDlgItem(IDC_BUTTON8)->SetWindowText((LPCWSTR)  std::wstring(s.begin(), s.end()).c_str()); 
*/
								}
								cout<<endl;
							}
					cout<<endl;
		}
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

}


#endif SOURCE_H