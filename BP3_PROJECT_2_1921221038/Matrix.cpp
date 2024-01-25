#include "Matrix.hpp"

Matrix::Matrix(size_t numRows, size_t numCols) : row(numRows), col(numCols)
//Constructor: Belirtilen satır ve sütun sayısına sahip bir matris oluşturur.
//elements adlı 2D vektörü, belirtilen boyutta ve karmaşık sayılarla doldurarak oluşturur.
{
    elements.resize(numRows, std::vector<Complex>(numCols));
}

Matrix::Matrix(const Matrix &src) : row(src.getRows()), col(src.getCols())
{ //Copy Constructor: Bir başka matrisin içeriğini kopyalar. Bu, bir matris nesnesini başka bir matris nesnesine atarken çağrılır.
    elements.resize(this->getRows(), std::vector<Complex>(this->getCols()));
    *this = src;
}

Matrix::~Matrix() {}

size_t Matrix::getRows() const //Matrisin satır sayısını döndüren bir getter fonksiyonu.
{
    return row;
}
 
size_t Matrix::getCols() const //Matrisin sütun sayısını döndüren bir getter fonksiyonu.
{
    return col;
}

void Matrix::setElement(size_t rowIndex, size_t colIndex, const Complex &value)
{ //Belirtilen konumdaki matris elemanını belirtilen karmaşık sayı değeri ile ayarlayan bir fonksiyon
    elements[rowIndex][colIndex] = value;
}

const Complex &Matrix::getElement(size_t rowIndex, size_t colIndex) const
{  //Belirtilen konumdaki matris elemanını döndüren bir getter fonksiyonu.
    return elements[rowIndex][colIndex];
}
//Transpozunu almak için kullanılan bir fonksiyon.
// Transpoz, bir matrisin satırlarını sütunlarına ve sütunlarını satırlarına dönüştürür.
Matrix Matrix::transpose() const
{
    Matrix res(this->getCols(), this->getRows());
    for (size_t i = 0; i < this->getRows(); ++i)
        for (size_t j = 0; j < this->getCols(); ++j)
            res.setElement(j, i, this->getElement(i, j));
    return res;
}

Complex Matrix::determinant() const //Kare Matrisin determinantını hesaplamak için kullanılan bir fonksiyon.
{
    size_t size = this->getRows(); //boyutu belirlemek için.
    Complex det(0.0, 0.0); //deteerminantı tutmk için.

    if (this->getRows() != this->getCols()) 
        return Complex();
    if (size == 1) //1x1 lik ise direkt kendisi 
        return this->getElement(0, 0);
    for (size_t j = 0; j < size; ++j)
    { //ilk satırın her elemanı kofaktörle çarpılır.
        Complex cofactor = this->getElement(0, j) * this->minorMatrix(0, j).determinant();
        if (j % 2 == 0) //kofaktörleri tek tek topluyoruz.
            det = det + cofactor;
        else
            det = det - cofactor;
    }
    return det;
}

Matrix Matrix::minorMatrix(size_t removedRow, size_t removedCol) const
{ //Belirtilen satır ve sütunu çıkartılmış bir matrisin minor matrisini oluşturan bir fonksiyon.
    Matrix minor(this->getRows() - 1, this->getCols() - 1);
    size_t minorRow = 0, minorCol = 0;

    for (size_t i = 0; i < this->getRows(); ++i) {
        if (i == removedRow)
            continue;
        for (size_t j = 0; j < this->getCols(); ++j) {
            if (j == removedCol)
                continue;
            minor.setElement(minorRow, minorCol, this->getElement(i, j));
            ++minorCol;
        }
        ++minorRow;
        minorCol = 0;
    }
    return minor;
}
//Bir matrisi başka bir matrise atayan operatör.
void Matrix::operator=(const Matrix &src)
{
    if (this->getRows() != src.getRows() || this->getCols() != src.getCols())
        return ;
    for (size_t i = 0; i < this->getRows(); ++i)
        for (size_t j = 0; j < this->getCols(); ++j)
            this->setElement(i, j, src.getElement(i, j));
}

Matrix Matrix::operator+(const Matrix &rhs) const
{ //İki matrisi toplayan operatör. 
    Matrix res(this->getRows(), this->getCols());
    if (this->getRows() != rhs.getRows() || this->getCols() != rhs.getCols())
        return *this;
    for (size_t i = 0; i < this->getRows(); ++i)
        for (size_t j = 0; j < this->getCols(); ++j)
            res.setElement(i, j, this->getElement(i, j) + rhs.getElement(i, j));
    return res;
}

Matrix Matrix::operator-(const Matrix &rhs) const
{
    Matrix res(this->getRows(), this->getCols());
    if (this->getRows() != rhs.getRows() || this->getCols() != rhs.getCols())
        return *this;
    for (size_t i = 0; i < this->getRows(); ++i)
        for (size_t j = 0; j < this->getCols(); ++j)
            res.setElement(i, j, this->getElement(i, j) - rhs.getElement(i, j));
    return res;
}

Matrix Matrix::operator*(const Matrix &rhs) const//İKİ matrisin çarpımı
{
    Matrix res(this->getRows(), this->getCols());
    if (this->getRows() != rhs.getRows() || this->getCols() != rhs.getCols() || this->getCols() != this->getRows())
        return *this;
        //Eğer sol operandın sütun sayısı sağ operandın satır sayısına eşit değilse veya sonuç 
        //matrisinin boyutları uyumsuzsa, işlemi gerçekleştirmek yerine sol operand matrisi (*this) geri döndürülür.
    for (size_t i = 0; i < this->getRows(); ++i) {
        for (size_t j = 0; j < this->getRows(); ++j) {
            Complex sum;
            for (size_t k = 0; k < this->getCols(); ++k) {
                sum = sum + (this->getElement(i, k) * rhs.getElement(k, j));
            }
            res.setElement(i, j, sum); //Hesaplanan toplam değeri, çarpım matrisinin ilgili indisine atanır.
        }
    }
    return res;
}

Matrix &Matrix::operator+=(const Matrix &rhs)
{
    if (this->getRows() != rhs.getRows() || this->getCols() != rhs.getCols())
        return *this;
    for (size_t i = 0; i < this->getRows(); ++i)
        for (size_t j = 0; j < this->getCols(); ++j)
            this->setElement(i, j, this->getElement(i, j) + rhs.getElement(i, j));
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &rhs)
{
    if (this->getRows() != rhs.getRows() || this->getCols() != rhs.getCols())
        return *this;
    for (size_t i = 0; i < this->getRows(); ++i)
        for (size_t j = 0; j < this->getCols(); ++j)
            this->setElement(i, j, this->getElement(i, j) - rhs.getElement(i, j));
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &rhs)
{
    if (this->getRows() != rhs.getRows() || this->getCols() != rhs.getCols() || this->getCols() != this->getRows())
        return *this;
    for (size_t i = 0; i < this->getRows(); ++i)
        for (size_t j = 0; j < this->getCols(); ++j)
            this->setElement(i, j, this->getElement(i, j) * rhs.getElement(i, j));
    return *this;
}

bool Matrix::operator==(const Matrix &rhs) const
{
    if (this->getRows() != rhs.getRows() || this->getCols() != rhs.getCols())
        return false;
    for (size_t i = 0; i < this->getRows(); ++i)
        for (size_t j = 0; j < this->getCols(); ++j)
            if (!(this->getElement(i, j) == rhs.getElement(i, j)))
                return false;
    return true;
}

void Matrix::print(void) const
{
    std::cout << *this << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
{ //Matrisi ekrana yazdırmak için kullanılan bir fonksiyon.
    for (size_t i = 0; i < matrix.getRows(); ++i) {
        for (size_t j = 0; j < matrix.getCols(); ++j)
            os << matrix.getElement(i, j).getRe() << " + " << matrix.getElement(i, j).getIm() << "i ";
		if (i != matrix.getRows() - 1)
       		os << std::endl;
    }
    return os;
}