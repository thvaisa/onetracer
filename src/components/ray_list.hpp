#ifndef RAYLIST_H
#define RAYLIST_H

#include "ray.hpp"
#include <stack>
#include <vector>

#define INITITIAL_STORAGE_SIZE 100

//Iterator that gives rays that are only "alive". Used to iterate ray_list and hide
//implementation for later modification
template <typename T>
class RayListIterator{
    private:

        T _iterator;

        friend class RayList;
        explicit RayListIterator(T iter) : _iterator(iter) {}
    public:
        Ray& operator*() const {
            return *_iterator;
        }

        //overload pre increment operator
        //We don't want to expose implementation of the raylist to outside
        //because how raylist handles ray will be changed
        RayListIterator<T>& operator++() {
            do {
                _iterator++;
            }while(_iterator->ray_status() == RAYSTATUS::DEAD);
            return *this;
        }

        // overload post increment operator
        RayListIterator<T> operator++(int) = delete;

        bool operator==(const RayListIterator<T>& iter) const {
            return this->_iterator == iter._iterator;
        }

        bool operator!=(const RayListIterator<T>& iter) const {
            return this->_iterator != iter._iterator;
        }
};



class RayList {
    public:
        RayList() : _ray_storage{std::vector<Ray>()}{
            _ray_storage.reserve(INITITIAL_STORAGE_SIZE);
        }

        RayList(const RayList& other) : _ray_storage{other._ray_storage} // copy constructor
        {}

        RayList(RayList&& other) noexcept : _ray_storage(std::move(other._ray_storage))  // move constructor
        {}

        RayList& operator=(const RayList& other) // copy assignment
        {
            return *this = RayList(other);
        }

        RayList& operator=(RayList&& other) noexcept // move assignment
        {
            _ray_storage = std::move(other._ray_storage);
            return *this;
        }

        ~RayList(){};

        Ray* get_new_ray(){
            _ray_storage.emplace_back(Ray());
            return &_ray_storage.back();
        }

        int get_size() const{
            return _ray_storage.size();
        }

        typedef RayListIterator<std::vector<Ray>::iterator> Iterator;
        //typedef RayListIterator<std::vector<Ray>::const_iterator> Const_iterator;

        Iterator begin() { return Iterator(_ray_storage.begin()); }
        //Const_iterator cbegin() const { return Const_iterator(_ray_storage.cbegin()); }

        Iterator end() { return Iterator(_ray_storage.end()); }
        //Const_iterator cend() const { return Const_iterator(_ray_storage.cend()); }

    private:
        std::vector<Ray> _ray_storage;

};







#endif

