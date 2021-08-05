#include "includes.h"


int main( ) {
	c_graph graph( 2 );
	//graph.show_edges( );
	graph.show_matrix_of_adjacency( );
	graph.transitive_graph( );
	graph.~c_graph( );

	system( "pause" );
	return 0;
}