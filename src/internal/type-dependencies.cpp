/*
 * %injeqt copyright begin%
 * Copyright 2014 Rafał Malinowski (rafal.przemyslaw.malinowski@gmail.com)
 * %injeqt copyright end%
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "type-dependencies.h"

namespace injeqt { namespace internal {

type_dependencies::type_dependencies(type dependent_type, dependencies dependency_list) :
	_dependent_type{std::move(dependent_type)},
	_dependency_list{std::move(dependency_list)}
{
}

const type & type_dependencies::dependent_type() const
{
	return _dependent_type;
}

const dependencies & type_dependencies::dependency_list() const
{
	return _dependency_list;
}

bool operator == (const type_dependencies &x, const type_dependencies &y)
{
	if (x.dependent_type() != y.dependent_type())
		return false;

	if (x.dependency_list() != y.dependency_list())
		return false;

	return true;
}

bool operator != (const type_dependencies &x, const type_dependencies &y)
{
	return !(x == y);
}

}}
