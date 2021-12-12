/**
 * @file
 *
 * @author Jonathan Wilson
 *
 * @brief Object Iterator
 *
 * @copyright Thyme is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */
#pragma once
#include "always.h"
#include "mempoolobj.h"
class Object;

class ObjectIterator : public MemoryPoolObject
{
public:
    virtual ~ObjectIterator() override;
    virtual Object *First() = 0;
    virtual Object *Next() = 0;
};

class SimpleObjectIterator : public ObjectIterator
{
    IMPLEMENT_POOL(SimpleObjectIterator);

public:
    virtual ~SimpleObjectIterator() override;
    virtual Object *First() override;
    virtual Object *Next() override;

private:
    struct Clump : public MemoryPoolObject
    {
        IMPLEMENT_NAMED_POOL(Clump, "SimpleObjectIteratorClumpPool");
        Clump *m_nextClump;
        Object *m_obj;
        float m_numeric;
    };

    Clump *m_firstClump;
    Clump *m_curClump;
    int m_clumpCount;
};