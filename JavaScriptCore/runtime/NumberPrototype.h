/*
 *  Copyright (C) 1999-2000 Harri Porten (porten@kde.org)
 *  Copyright (C) 2008, 2011 Apple Inc. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef NumberPrototype_h
#define NumberPrototype_h

#include "NumberObject.h"

namespace JSC {

    class NumberPrototype : public NumberObject {
    public:
        typedef NumberObject Base;

        static NumberPrototype* create(ExecState* exec, JSGlobalObject* globalObject, Structure* structure)
        {
            NumberPrototype* prototype = new (NotNull, allocateCell<NumberPrototype>(*exec->heap())) NumberPrototype(exec, structure);
            prototype->finishCreation(exec, globalObject);
            return prototype;
        }
        
        DECLARE_INFO;

        static Structure* createStructure(VM& vm, JSGlobalObject* globalObject, JSValue prototype)
        {
            return Structure::create(vm, globalObject, prototype, TypeInfo(NumberObjectType, StructureFlags), info());
        }

    protected:
        void finishCreation(ExecState*, JSGlobalObject*);
        static const unsigned StructureFlags = OverridesGetOwnPropertySlot | NumberObject::StructureFlags;

    private:
        NumberPrototype(ExecState*, Structure*);
        static bool getOwnPropertySlot(JSObject*, ExecState*, PropertyName, PropertySlot&);
    };

} // namespace JSC

#endif // NumberPrototype_h
