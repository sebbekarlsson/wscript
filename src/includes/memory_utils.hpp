template <class classType>
classType free_vector(std::vector<classType> vec) {
    vec.clear();
    std::vector<classType>(vec).swap(vec);
};
