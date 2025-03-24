#include <iostream>
#include <cstring>

using namespace std;

class String
{
    char *data;
    size_t size;

public:
    /**
     * @brief Construct a new String object and it should have a default value of ""
     *
     */
    String() : size(0)
    {
        data = new char[1];
        data[0] = '\0';
    }

    /**
     * @brief Construct a new String object with the provided value
     *
     * @param str
     */
    String(const char *str) : size(strlen(str))
    {
        data = new char[size + 1];
        strcpy(data, str);
    }

	/**
     * @brief Construct a new String object by copying another string
     *
     * @param other
     */
    String(const String &other) : size(other.size)
    {
        data = new char[size + 1];
        strcpy(data, other.data);
    }

    /**
     * @brief Copies the values from the other string in this string
     *
     * @param other
     * @return String&
     */
    String &operator=(const String &other)
    {
        if (this != &other)
        {
            delete[] data;
            size = other.size;
            data = new char[size + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    /**
     * @brief Inserts a character at the provided index, if the index is bigger than the size of the string, just return the string, withouth modifying it
     *
     * @param index
     * @param c
     * @return String&
     */
    String &insert(size_t index, char c)
    {
        if (index > size)
        {
            return *this;
        }

        char *newData = new char[size + 2];
        strncpy(newData, data, index);
        newData[index] = c;
        strcpy(newData + index + 1, data + index);
        delete[] data;
        data = newData;
        size++;
        return *this;
    }

    /**
     * @brief Replaces the character at the provided index, if the index is bigger than the size of the string, just return the string, withouth modifying it
     *
     * @param index
     * @param c
     * @return String&
     */
    String &replace(size_t index, char c)
    {
        if (index >= size)
        {
            return *this;
        }
        data[index] = c;
        return *this;
    }

    /**
     * @brief Finds the first index, where the provided character is found, return -1 if the character is not found
     *
     * @param c
     * @return int
     */
    int findFirstOf(char c) const
    {
        for (size_t i = 0; i < size; i++)
        {
            if (data[i] == c)
            {
                return i;
            }
        }
        return -1;
    }

    /**
     * @brief Destroy the String object
     *
     */
    ~String()
    {
        delete[] data;
    }

    /**
     * @brief Returns the string as a C-style string - char*
     *
     * @return const char*
     */
    const char *toCString() const
    {
        return data;
    }

    /**
     * @brief Returns the length of the string
     *
     * @return size_t
     */
    size_t length() const
    {
        return size;
    }

    /**
     * @brief Appends a character to the string
     *
     * @param ch
     */
    void append(char ch)
    {
        char *newData = new char[size + 2];
        strcpy(newData, data);
        newData[size] = ch;
        newData[size + 1] = '\0';
        delete[] data;
        data = newData;
        size++;
    }

    /**
     * @brief Append the provided string to the current string
     *
     * @param str
     */
    void concat(const char *str)
    {
        size_t newSize = size + strlen(str);
        char *newData = new char[newSize + 1];
        strcpy(newData, data);
        strcat(newData, str);
        delete[] data;
        data = newData;
        size = newSize;
    }

    /**
     * @brief Compares 2 strings
     *
     * @param other
     * @return int 0 if the strings are equal, 1 if the current string is greater, -1 if the current string is smaller
     */
    int compare(const String &other) const
    {
        return strcmp(data, other.data);
    }
};