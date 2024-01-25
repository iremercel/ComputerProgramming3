# Makefile

# Derleme işlemi için kullanılacak C++ derleyicisi
CXX = g++

# Derleme seçenekleri ve uyarıları
CXXFLAGS = -std=c++11 -Wall

# Hedef dosyasının adı
TARGET = myprogram

# Kaynak dosyaları
SOURCES = main.cpp Imaginary.cpp Complex.cpp Vector.cpp Matrix.cpp \
          SquareMatrix.cpp IdentityMatrix.cpp TriangularMatrix.cpp \
          LinearAlgebraObject.cpp

# Nesne dosyaları (derleme işleminden sonra oluşturulacak)
OBJECTS = $(SOURCES:.cpp=.o)

# Temizleme işlemi
RM = rm -f

# Hedef: varsayılan olarak hedef dosyasını derle
all: $(TARGET)

# Hedef dosyasını derleme işlemi
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Nesne dosyalarını derleme işlemi
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Temizleme işlemi
clean:
	$(RM) $(TARGET) $(OBJECTS)
