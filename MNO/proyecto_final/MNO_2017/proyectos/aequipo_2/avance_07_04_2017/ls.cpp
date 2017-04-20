/**
 * @file ls.cpp
 * @author Robert Smith <rws20@zips.uakron.edu>
 */


#include "ls.hpp"

void ls_finalizer(LS* ls) {
	ls->clear();
}

// LS stands for "least squares"

LS::LS() : Data(), data() {}
	
LS::LS(arma::colvec Y_, arma::mat X_) :	Data(Y_, X_), data() {}
	
LS::LS(const LS& o) :	Data(), data() {
	LS* ls = o.clone();
	
	setX( ls->getX() );
	setY( ls->getY() );
	setData( ls->getData() );
}
	
LS* LS::clone() const {
	return new LS(*this);
}
	
size_t LS::getMaxSize() {
	return data.max_size;
}

bool LS::operator==(const LS& rhs) const {
	bool xcomp = (arma::accu(X) - arma::accu(rhs.X) < std::numeric_limits< double >::epsilon( ) );
	bool ycomp = (arma::accu(Y) - arma::accu(rhs.Y) < std::numeric_limits< double >::epsilon( ) );
	bool dcomp = ( data == rhs.getData() );
	
	return ( xcomp && ycomp && dcomp );
	
}

bool LS::operator!=( const LS& rhs ) const {
	return !(*this == rhs);
}

LS& LS::operator=( const LS& rhs ) {
	if (*this != rhs) {
		LS* ls = rhs.clone();
		
		setY( ls->getY() );
		setX( ls->getX() );
		data = ls->data;
	} 
	return *this;
}

	// single OLS fit
Output LS::OLS(std::vector<unsigned int> input) {
	
	// advanced constructors offer speed benefits becuase X & Y are not changed
	arma::mat localX( subsetX(input) );
	
	Output o;
	o.columns = input;
	arma::colvec beta = arma::solve( localX, Y );
	arma::colvec error = Y - localX * beta;
	o.sse = arma::accu( error.t() * error ); 
	o.cp = (o.sse / (o.sse / (localX.n_rows - localX.n_cols))) - localX.n_rows + (2 * localX.n_cols);
	o.aic = localX.n_rows * log(o.sse) - localX.n_rows * log( localX.n_rows ) + (2 * localX.n_cols );
	
	return o;
}

/**
 * 
 */
void LS::BestSubsetHelper(unsigned int K) {
	std::vector<unsigned int> combination( ncolX(), 0 );
	std::vector<unsigned int> temp_combos( K, 0 );
	
	for(unsigned int i = 0; i < X.n_cols; i++) {
		combination[i] = (1+i);
	}
	
	do {
		for ( unsigned int i = 0; i < K; i++ ) {
			temp_combos[i] = combination[i];
		}
		
		data.insert( OLS( temp_combos ) );
		
	} while (boost::next_combination(combination.begin(), combination.begin() + K, combination.end()));
}
	
void LS::BestSubset() {
	clear(); // remove older values
	
	for (size_t i = 1; i < ( 1 + ncolX() ); i++) {
		BestSubsetHelper( i );
	}
	
	data.prune();
}
	
void LS::ompBestSubsetHelper(unsigned int K) {
	OutVec local;
	std::vector<unsigned int> combination( ncolX(), 0 );
	std::vector<unsigned int> temp_combos( K, 0 );
	
	for(unsigned int i = 0; i < X.n_cols; i++) {
		combination[i] = (1+i);
	}
	
	do {
		for ( unsigned int i = 0; i < K; i++ ) {
			temp_combos[i] = combination[i];
		}
		
		local.insert( OLS( temp_combos ) );
		
		
	#pragma omp critical
	{
		data.insert(local);
	}
		
	} while (boost::next_combination(combination.begin(), combination.begin() + K, combination.end()));
}
	
void LS::ompBestSubset() {
	clear(); // remove older values
	
	// dynamic scheduling due to ordering not being important
#pragma omp parallel for schedule(dynamic) default(shared)
	for (size_t i = 1; i < ( 1 + ncolX() ); i++) {
		ompBestSubsetHelper( i ) ;
	}
}
	
void LS::clear() {
	data.clear();
}

void LS::print() {
	Data::print();
	data.print();
}
	
void LS::setData( const OutVec& ov ){
	data.clear();
	data.insert(ov);
}

const OutVec& LS::getData() const {
	return data;
}

