/*
 * *Author:-Pukar Giri
 * *Created On:-22Th February 2018 at 12:00
 * *Licence:- MIT
 * *Email:-crazzy.lx75@gmail.com
 * */
#include <iostream>
#include <iomanip>
#include <vector>
class matrix//class implemented to support matrix of any size
{
    private:
        std::vector<float>mat;
        int rows;
        int cols;
    public:
        matrix(int rows,int cols)//create a matrix object of dimensions rows x columns
        {
            this->rows=rows;
            this->cols=cols;
        }
        void init(float no)//for creating matrix having same value as all elements
        {
            for(int colno=0;colno<cols;colno++)
            {
                for (int rowno=0;rowno<rows;rowno++)
                {
                    mat.push_back(no);
                }
            }
        }
        void set_elem(float elem,int i ,int j)//set the value of i,j th element as elem
        {
            i-=1;
            j-=1;
            mat.at(i*cols+j)=elem;
        }
	template <size_t rowno, size_t colno>
        void set_matrix(float (&num)[rowno][colno])
        {
            for(int i=0;i<rows;i++)
            {
                for (int j=0;j<cols;j++)
                {
                  mat.push_back(num[i][j]);
                }
            }
        }
	float & at(int i,int j)
	{
		return this->mat.at(i*this->cols+j);
	}
	friend matrix operator+(matrix& mat1,matrix& mat2)
	{
		//std::cout<<"Adding the matrix"<<std::endl;
		if (mat1.rows!=mat2.rows||mat1.cols!=mat2.cols)
		{
			throw std::length_error("Cannot add two arrays with diffrent dimensions");
		}
		matrix rmat(mat2.rows,mat2.cols);
		rmat.init(0);
		for(int i=0;i<mat1.rows;i++)
            {
                for (int j=0;j<mat1.cols;j++)
                {
                  rmat.at(i,j)=mat2.at(i,j)+mat1.at(i,j);
		    
                }
            }
	return rmat;
	}
	matrix T()
	{
		matrix rmat(rows,cols);
		rmat.init(0);
	for(int i=0;i<rows;i++)
           {
                for (int j=0;j<cols;j++)
                {
                  rmat.at(j,i)=this->at(i,j);
		    
                }
            }
	return rmat;
		
	}
        friend std::ostream& operator<<(std::ostream &out,matrix &mat1)
        {
	   for(int i=0;i<mat1.rows;i++)
            {
                out<<"|";
                for (int j=0;j<mat1.cols;j++)
                {
                    out<<std::setw(4)<<std::right<<mat1.mat[i*mat1.cols+j];
                }
                out<<" |"<<std::endl;
            }
            return out;
        }
};

int main()
{
    matrix mat1(3,3);
    matrix mat2(3,3);
    float no[][3]={
                {1,2,3},
                {4,5,6},
                {7,8,9}
			};
    mat2.set_matrix(no); 
    std::cout<<mat2<<std::endl;
    mat1.init(0);
    mat1.set_elem(5,2,2);
    std::cout<<mat1<<std::endl;
    matrix mat3=mat2+mat1;//checking the addition of two matrices
    std::cout<<mat3<<std::endl;
    matrix mat3T=mat3.T();//checking the transpose of two matrices
    std::cout<<mat3T<<std::endl;
}
