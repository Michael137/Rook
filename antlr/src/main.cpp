#include "Game.h"
#include "Visitor.h"
#include <RookLexer.h>
#include <RookParser.h>
#include <antlr4-runtime.h>
#include <iostream>

using namespace rook;

int main()
{
	// std::string stream( "1. e4 e5\n2. Nf3 Nc6\n3. Bb5 a6\n4. Bxc6 dxc6\n5.
	// O-O 1-0 (black resigns)\n\n" );
	//	std::string stream( R"(
	// 1. e4 e5
	// 2. Nf3 Nc6
	// 3. Bb5 a6
	// 4. Bxc6 dxc6
	// 5. O-O 1-0 (black resigns)
	//)" );
	std::ifstream stream( "test/test_basic.in" );

	antlr4::ANTLRInputStream input( stream );

	RookLexer lexer( &input );
	antlr4::CommonTokenStream tokens( &lexer );

	tokens.fill();
	for( auto token : tokens.getTokens() ) {
		std::cout << token->toString() << std::endl;
	}

	RookParser parser( &tokens );
	antlr4::tree::ParseTree* tree = parser.game();

	std::cout << tree->toStringTree( &parser ) << std::endl;

	Visitor visitor;
	Game game = visitor.visitGame( reinterpret_cast<RookParser::GameContext*>( tree ) );

	// Call into ncurses here

	return 0;
}
