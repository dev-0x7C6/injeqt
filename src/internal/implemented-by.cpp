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

#include "implemented-by.h"

#include <injeqt/type.h>

#include "interfaces-utils.h"

#include <cassert>

namespace injeqt { namespace internal {

implemented_by::implemented_by(type interface_type, type implementation_type) :
	_interface_type{std::move(interface_type)},
	_implementation_type{std::move(implementation_type)}
{
	assert(!_interface_type.is_empty());
	assert(!_implementation_type.is_empty());
	assert(implements(_implementation_type, _interface_type));
}

type implemented_by::interface_type() const
{
	return _interface_type;
}

type implemented_by::implementation_type() const
{
	return _implementation_type;
}

bool operator == (const implemented_by &x, const implemented_by &y)
{
	if (x.interface_type() != y.interface_type())
		return false;

	if (x.implementation_type() != y.implementation_type())
		return false;

	return true;
}

bool operator != (const implemented_by &x, const implemented_by &y)
{
	return !(x == y);
}

}}
