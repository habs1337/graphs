#include "includes.h"


c_graph::c_graph( ) {
	m_matrix_of_adjacency = nullptr;
	m_graph_size = 0;
	m_matrix_of_adjency_size = 0;
}

void c_graph::init_ptr( unsigned short& size, const int& n, int**& arr ) {
	size = n;
	arr = new int* [ size ];
	for ( int counter = 0; counter < size; counter++ ) {
		arr [ counter ] = new int [ size ];
	}
}


void c_graph::push_values( ) {
	int max_value = -1;
	cout << "input edges:\n"; //рёбра 

	for ( int i = 0; i < 4; i++ ) {
		int value;
		cin >> value;
		m_graph.push_back( value );
		if ( value > max_value ) {
			max_value = value;
		}
	}

	m_graph_size = m_graph.size( );
	m_matrix_of_adjency_size = max_value;
}

void c_graph::create_matrix_of_adhency( ) {
	for ( int i = 0; i < m_matrix_of_adjency_size; i++ ) {
		for ( int j = 0; j < m_matrix_of_adjency_size; j++ ) {
			m_matrix_of_adjacency [ i ][ j ] = 0;
		}
	}

	for ( int front_counter = 0, back_counter = m_graph_size - 1; front_counter < m_graph_size - 1; front_counter += 2, back_counter -= 2 ) {
		int first_idx = m_graph.at( front_counter ) - 1, second_idx = m_graph.at( front_counter + 1 ) - 1;
		m_matrix_of_adjacency [ first_idx ][ second_idx ] = 1;
		first_idx = m_graph.at( back_counter ) - 1, second_idx = m_graph.at( back_counter - 1 ) - 1;
		m_matrix_of_adjacency [ first_idx ][ second_idx ] = 1;
	}
}

void c_graph::show_edges( ) {
	cout << "edges:\n";
	for ( auto& graph : m_graph ) {
		cout << graph << endl;
	}
}

void c_graph::show_matrix_of_adjacency( ) {
	cout << "matrix_of_adjacency:\n";

	for ( int i = 0; i < m_matrix_of_adjency_size; i++ ) {
		for ( int j = 0; j < m_matrix_of_adjency_size; j++ ) {
			cout << setw( 3 ) << m_matrix_of_adjacency [ i ][ j ];
		}
		cout << endl;
	}
}

void c_graph::transitive_graph( ) {
	for ( int i = 0; i < m_matrix_of_adjency_size; i++ ) {
		for ( int j = 0; j < m_matrix_of_adjency_size; j++ ) {
			if ( m_matrix_of_adjacency [ i ][ j ] ) {
				for ( int k = 0; k < m_matrix_of_adjency_size; k++ ) {
					// если мы не в начальной вершине и из вершины j в вершину k ведёт ребро, но из i в k - нет, то граф транзитивен
					if ( k != i && m_matrix_of_adjacency [ j ][ k ] && !m_matrix_of_adjacency [ i ][ k ] ) {
						cout << "transitive graph\n";
						return;
					}
				}
			}
		}
	}
	cout << "not transitive graph\n";
}

c_graph::c_graph( const int& n ) {
	push_values( );
	init_ptr( m_matrix_of_adjency_size, m_matrix_of_adjency_size, m_matrix_of_adjacency );
	create_matrix_of_adhency( );
}


c_graph::~c_graph( ) {
	if ( m_matrix_of_adjacency ) {
		for ( int counter = 0; counter < m_matrix_of_adjency_size; counter++ )
			delete [ ] m_matrix_of_adjacency [ counter ];
		delete [ ] m_matrix_of_adjacency;
		m_matrix_of_adjacency = nullptr;
	}
}