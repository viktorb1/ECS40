template <class T>
Vector<T>::Vector(int initSize) : count(0), size(initSize)
{
  array = new T[initSize];
} // Vector()


template <class T>
Vector<T>::~Vector()
{
  delete [] array;
} // ~Vector()


template <class T>
int Vector<T>::getCount() const
{
  return count;
} // getCount()


template <class T>
const T& Vector<T>::operator[](int index) const
{
  return array[index];
} // operator[] const


template <class T>
T& Vector<T>::operator[](int index)
{
  return array[index];
} // operator[]


template <class T>
int Vector<T>::operator+=(const T &object)
{
  int pos; 
    
  for(pos = 0; 
     pos < count && ! (object == array[pos]); pos++); 

  if(pos == count) // not found
  {
    if(count == size)
    {
      T *temp = new T[size * 2];
      
      for(int i = 0; i < count; i++)
        temp[i] = array[i];
      
      delete [] array;
      array = temp;
      size *= 2;
    } // if need to resize

    for(pos = count - 1; 
      pos >= 0 && object < array[pos]; pos--)
        array[pos + 1] = array[pos];

    array[++pos] = object;  // copy the new T into pos + 1
    count++;
  } // if not found
  
  return pos;
}  // operator+=