#include <iostream>
#include <algorithm>

class AtmintiesBlokas
{
public:

    explicit AtmintiesBlokas(size_t length)
        : _ilgis(length)
        , _duomenys(new int[length])
    {
    }

    ~AtmintiesBlokas()
    {
        if (_duomenys != nullptr)
        {
            delete[] _duomenys;
        }
    }

    AtmintiesBlokas(const AtmintiesBlokas& kitas)
        : _ilgis(kitas._ilgis)
        , _duomenys(new int[kitas._ilgis])
    {
        std::copy(kitas._duomenys, kitas._duomenys + _ilgis, _duomenys);
    }

    AtmintiesBlokas(AtmintiesBlokas&& kitas) noexcept
        : _duomenys(nullptr)
        , _ilgis(0)
    {
        _duomenys = kitas._duomenys;
        _ilgis = kitas._ilgis;

        kitas._duomenys = nullptr;
        kitas._ilgis = 0;
    }

    AtmintiesBlokas& operator=(AtmintiesBlokas&& kitas) noexcept
    {
        if (this != &kitas)
        {
            delete[] _duomenys;

            _duomenys = kitas._duomenys;
            _ilgis = kitas._ilgis;
            
            kitas._duomenys = nullptr;
            kitas._ilgis = 0;
        }
        return *this;
    }

    size_t Ilgis() const
    {
        return _ilgis;
    }

private:
    size_t _ilgis;
    int* _duomenys;
};