
class c_graph {
	vector<int> m_graph;
	int** m_matrix_of_adjacency = nullptr;
	unsigned short m_graph_size = 0, m_matrix_of_adjency_size = 0;
	void init_ptr(unsigned short& size, const int& n, int**& arr );
	void push_values( );
	void create_matrix_of_adhency( );
public:
	void show_edges( );
	void show_matrix_of_adjacency( );
	void transitive_graph( );
	c_graph( );
	c_graph( const int& n );
	~c_graph( );
};