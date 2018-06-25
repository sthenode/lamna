///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: shape_item.hpp
///
/// Author: $author$
///   Date: 6/12/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_GRAPHIC_SHAPE_ITEM_HPP
#define _XOS_GRAPHIC_SHAPE_ITEM_HPP

#include "xos/graphic/image.hpp"
#include "xos/base/linked/item.hpp"

namespace xos {
namespace graphic {

class _EXPORT_CLASS shape_interface;
class _EXPORT_CLASS shape_item;

typedef linked::itemt<shape_item> shape_item_extends;
///////////////////////////////////////////////////////////////////////
///  Class: shape_item
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS shape_item: public shape_item_extends {
public:
    typedef shape_item_extends extends;

    shape_item(shape_interface& shape): shape_(shape) {
    }
    virtual ~shape_item() {
    }

    virtual shape_interface& shape() const {
        return (shape_interface&)shape_;
    }

protected:
    shape_interface& shape_;
};

} /// namespace graphic
} /// namespace xos

#endif /// _XOS_GRAPHIC_SHAPE_ITEM_HPP 
