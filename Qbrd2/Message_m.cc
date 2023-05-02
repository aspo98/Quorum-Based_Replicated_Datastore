//
// Generated file, do not edit! Created by opp_msgtool 6.0 from Message.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "Message_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

class VectorDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
    };
  public:
    VectorDescriptor();
    virtual ~VectorDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(VectorDescriptor)

VectorDescriptor::VectorDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(Vector)), "")
{
    propertyNames = nullptr;
}

VectorDescriptor::~VectorDescriptor()
{
    delete[] propertyNames;
}

bool VectorDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Vector *>(obj)!=nullptr;
}

const char **VectorDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *VectorDescriptor::getProperty(const char *propertyName) const
{
    if (!strcmp(propertyName, "existingClass")) return "";
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int VectorDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 0+base->getFieldCount() : 0;
}

unsigned int VectorDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    return 0;
}

const char *VectorDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

int VectorDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->findField(fieldName) : -1;
}

const char *VectorDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

const char **VectorDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *VectorDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int VectorDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Vector *pp = omnetpp::fromAnyPtr<Vector>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void VectorDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Vector *pp = omnetpp::fromAnyPtr<Vector>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Vector'", field);
    }
}

const char *VectorDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Vector *pp = omnetpp::fromAnyPtr<Vector>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string VectorDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Vector *pp = omnetpp::fromAnyPtr<Vector>(object); (void)pp;
    switch (field) {
        default: return "";
    }
}

void VectorDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Vector *pp = omnetpp::fromAnyPtr<Vector>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Vector'", field);
    }
}

omnetpp::cValue VectorDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Vector *pp = omnetpp::fromAnyPtr<Vector>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Vector' as cValue -- field index out of range?", field);
    }
}

void VectorDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Vector *pp = omnetpp::fromAnyPtr<Vector>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Vector'", field);
    }
}

const char *VectorDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

omnetpp::any_ptr VectorDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Vector *pp = omnetpp::fromAnyPtr<Vector>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void VectorDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Vector *pp = omnetpp::fromAnyPtr<Vector>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Vector'", field);
    }
}

class DataItemDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
    };
  public:
    DataItemDescriptor();
    virtual ~DataItemDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(DataItemDescriptor)

DataItemDescriptor::DataItemDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DataItem)), "")
{
    propertyNames = nullptr;
}

DataItemDescriptor::~DataItemDescriptor()
{
    delete[] propertyNames;
}

bool DataItemDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DataItem *>(obj)!=nullptr;
}

const char **DataItemDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DataItemDescriptor::getProperty(const char *propertyName) const
{
    if (!strcmp(propertyName, "existingClass")) return "";
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DataItemDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 0+base->getFieldCount() : 0;
}

unsigned int DataItemDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    return 0;
}

const char *DataItemDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

int DataItemDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->findField(fieldName) : -1;
}

const char *DataItemDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

const char **DataItemDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *DataItemDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int DataItemDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DataItem *pp = omnetpp::fromAnyPtr<DataItem>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DataItemDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DataItem *pp = omnetpp::fromAnyPtr<DataItem>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DataItem'", field);
    }
}

const char *DataItemDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DataItem *pp = omnetpp::fromAnyPtr<DataItem>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DataItemDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DataItem *pp = omnetpp::fromAnyPtr<DataItem>(object); (void)pp;
    switch (field) {
        default: return "";
    }
}

void DataItemDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DataItem *pp = omnetpp::fromAnyPtr<DataItem>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataItem'", field);
    }
}

omnetpp::cValue DataItemDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DataItem *pp = omnetpp::fromAnyPtr<DataItem>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DataItem' as cValue -- field index out of range?", field);
    }
}

void DataItemDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DataItem *pp = omnetpp::fromAnyPtr<DataItem>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataItem'", field);
    }
}

const char *DataItemDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

omnetpp::any_ptr DataItemDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DataItem *pp = omnetpp::fromAnyPtr<DataItem>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DataItemDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DataItem *pp = omnetpp::fromAnyPtr<DataItem>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataItem'", field);
    }
}

Register_Class(PutRequest)

PutRequest::PutRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

PutRequest::PutRequest(const PutRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

PutRequest::~PutRequest()
{
}

PutRequest& PutRequest::operator=(const PutRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PutRequest::copy(const PutRequest& other)
{
    this->writeQuorum = other.writeQuorum;
    this->key = other.key;
    this->value = other.value;
    this->putIdClientSide = other.putIdClientSide;
}

void PutRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->writeQuorum);
    doParsimPacking(b,this->key);
    doParsimPacking(b,this->value);
    doParsimPacking(b,this->putIdClientSide);
}

void PutRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->writeQuorum);
    doParsimUnpacking(b,this->key);
    doParsimUnpacking(b,this->value);
    doParsimUnpacking(b,this->putIdClientSide);
}

const Vector& PutRequest::getWriteQuorum() const
{
    return this->writeQuorum;
}

void PutRequest::setWriteQuorum(const Vector& writeQuorum)
{
    this->writeQuorum = writeQuorum;
}

int PutRequest::getKey() const
{
    return this->key;
}

void PutRequest::setKey(int key)
{
    this->key = key;
}

int PutRequest::getValue() const
{
    return this->value;
}

void PutRequest::setValue(int value)
{
    this->value = value;
}

int PutRequest::getPutIdClientSide() const
{
    return this->putIdClientSide;
}

void PutRequest::setPutIdClientSide(int putIdClientSide)
{
    this->putIdClientSide = putIdClientSide;
}

class PutRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_writeQuorum,
        FIELD_key,
        FIELD_value,
        FIELD_putIdClientSide,
    };
  public:
    PutRequestDescriptor();
    virtual ~PutRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(PutRequestDescriptor)

PutRequestDescriptor::PutRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PutRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

PutRequestDescriptor::~PutRequestDescriptor()
{
    delete[] propertyNames;
}

bool PutRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PutRequest *>(obj)!=nullptr;
}

const char **PutRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PutRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PutRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int PutRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_writeQuorum
        FD_ISEDITABLE,    // FIELD_key
        FD_ISEDITABLE,    // FIELD_value
        FD_ISEDITABLE,    // FIELD_putIdClientSide
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *PutRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "writeQuorum",
        "key",
        "value",
        "putIdClientSide",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int PutRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "writeQuorum") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "key") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "value") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "putIdClientSide") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *PutRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Vector",    // FIELD_writeQuorum
        "int",    // FIELD_key
        "int",    // FIELD_value
        "int",    // FIELD_putIdClientSide
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **PutRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *PutRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int PutRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PutRequest *pp = omnetpp::fromAnyPtr<PutRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PutRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PutRequest *pp = omnetpp::fromAnyPtr<PutRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PutRequest'", field);
    }
}

const char *PutRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PutRequest *pp = omnetpp::fromAnyPtr<PutRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PutRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PutRequest *pp = omnetpp::fromAnyPtr<PutRequest>(object); (void)pp;
    switch (field) {
        case FIELD_writeQuorum: return "";
        case FIELD_key: return long2string(pp->getKey());
        case FIELD_value: return long2string(pp->getValue());
        case FIELD_putIdClientSide: return long2string(pp->getPutIdClientSide());
        default: return "";
    }
}

void PutRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PutRequest *pp = omnetpp::fromAnyPtr<PutRequest>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(string2long(value)); break;
        case FIELD_value: pp->setValue(string2long(value)); break;
        case FIELD_putIdClientSide: pp->setPutIdClientSide(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PutRequest'", field);
    }
}

omnetpp::cValue PutRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PutRequest *pp = omnetpp::fromAnyPtr<PutRequest>(object); (void)pp;
    switch (field) {
        case FIELD_writeQuorum: return omnetpp::toAnyPtr(&pp->getWriteQuorum()); break;
        case FIELD_key: return pp->getKey();
        case FIELD_value: return pp->getValue();
        case FIELD_putIdClientSide: return pp->getPutIdClientSide();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PutRequest' as cValue -- field index out of range?", field);
    }
}

void PutRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PutRequest *pp = omnetpp::fromAnyPtr<PutRequest>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_value: pp->setValue(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_putIdClientSide: pp->setPutIdClientSide(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PutRequest'", field);
    }
}

const char *PutRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_writeQuorum: return omnetpp::opp_typename(typeid(Vector));
        default: return nullptr;
    };
}

omnetpp::any_ptr PutRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PutRequest *pp = omnetpp::fromAnyPtr<PutRequest>(object); (void)pp;
    switch (field) {
        case FIELD_writeQuorum: return omnetpp::toAnyPtr(&pp->getWriteQuorum()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PutRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PutRequest *pp = omnetpp::fromAnyPtr<PutRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PutRequest'", field);
    }
}

Register_Class(UpdatePacket)

UpdatePacket::UpdatePacket(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

UpdatePacket::UpdatePacket(const UpdatePacket& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

UpdatePacket::~UpdatePacket()
{
}

UpdatePacket& UpdatePacket::operator=(const UpdatePacket& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void UpdatePacket::copy(const UpdatePacket& other)
{
    this->keyValueItem = other.keyValueItem;
}

void UpdatePacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->keyValueItem);
}

void UpdatePacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->keyValueItem);
}

const DataItem& UpdatePacket::getKeyValueItem() const
{
    return this->keyValueItem;
}

void UpdatePacket::setKeyValueItem(const DataItem& keyValueItem)
{
    this->keyValueItem = keyValueItem;
}

class UpdatePacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_keyValueItem,
    };
  public:
    UpdatePacketDescriptor();
    virtual ~UpdatePacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(UpdatePacketDescriptor)

UpdatePacketDescriptor::UpdatePacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(UpdatePacket)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

UpdatePacketDescriptor::~UpdatePacketDescriptor()
{
    delete[] propertyNames;
}

bool UpdatePacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UpdatePacket *>(obj)!=nullptr;
}

const char **UpdatePacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *UpdatePacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int UpdatePacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int UpdatePacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_keyValueItem
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *UpdatePacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "keyValueItem",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int UpdatePacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "keyValueItem") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *UpdatePacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "DataItem",    // FIELD_keyValueItem
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **UpdatePacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *UpdatePacketDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int UpdatePacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    UpdatePacket *pp = omnetpp::fromAnyPtr<UpdatePacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void UpdatePacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    UpdatePacket *pp = omnetpp::fromAnyPtr<UpdatePacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'UpdatePacket'", field);
    }
}

const char *UpdatePacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    UpdatePacket *pp = omnetpp::fromAnyPtr<UpdatePacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UpdatePacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    UpdatePacket *pp = omnetpp::fromAnyPtr<UpdatePacket>(object); (void)pp;
    switch (field) {
        case FIELD_keyValueItem: return "";
        default: return "";
    }
}

void UpdatePacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UpdatePacket *pp = omnetpp::fromAnyPtr<UpdatePacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UpdatePacket'", field);
    }
}

omnetpp::cValue UpdatePacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    UpdatePacket *pp = omnetpp::fromAnyPtr<UpdatePacket>(object); (void)pp;
    switch (field) {
        case FIELD_keyValueItem: return omnetpp::toAnyPtr(&pp->getKeyValueItem()); break;
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'UpdatePacket' as cValue -- field index out of range?", field);
    }
}

void UpdatePacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UpdatePacket *pp = omnetpp::fromAnyPtr<UpdatePacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UpdatePacket'", field);
    }
}

const char *UpdatePacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_keyValueItem: return omnetpp::opp_typename(typeid(DataItem));
        default: return nullptr;
    };
}

omnetpp::any_ptr UpdatePacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    UpdatePacket *pp = omnetpp::fromAnyPtr<UpdatePacket>(object); (void)pp;
    switch (field) {
        case FIELD_keyValueItem: return omnetpp::toAnyPtr(&pp->getKeyValueItem()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void UpdatePacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    UpdatePacket *pp = omnetpp::fromAnyPtr<UpdatePacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UpdatePacket'", field);
    }
}

Register_Class(AbortMessage)

AbortMessage::AbortMessage(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

AbortMessage::AbortMessage(const AbortMessage& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

AbortMessage::~AbortMessage()
{
}

AbortMessage& AbortMessage::operator=(const AbortMessage& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void AbortMessage::copy(const AbortMessage& other)
{
    this->key = other.key;
    this->putIdClientSide = other.putIdClientSide;
    this->clientId = other.clientId;
}

void AbortMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->key);
    doParsimPacking(b,this->putIdClientSide);
    doParsimPacking(b,this->clientId);
}

void AbortMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->key);
    doParsimUnpacking(b,this->putIdClientSide);
    doParsimUnpacking(b,this->clientId);
}

int AbortMessage::getKey() const
{
    return this->key;
}

void AbortMessage::setKey(int key)
{
    this->key = key;
}

int AbortMessage::getPutIdClientSide() const
{
    return this->putIdClientSide;
}

void AbortMessage::setPutIdClientSide(int putIdClientSide)
{
    this->putIdClientSide = putIdClientSide;
}

int AbortMessage::getClientId() const
{
    return this->clientId;
}

void AbortMessage::setClientId(int clientId)
{
    this->clientId = clientId;
}

class AbortMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_key,
        FIELD_putIdClientSide,
        FIELD_clientId,
    };
  public:
    AbortMessageDescriptor();
    virtual ~AbortMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(AbortMessageDescriptor)

AbortMessageDescriptor::AbortMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(AbortMessage)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

AbortMessageDescriptor::~AbortMessageDescriptor()
{
    delete[] propertyNames;
}

bool AbortMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AbortMessage *>(obj)!=nullptr;
}

const char **AbortMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *AbortMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int AbortMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int AbortMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_key
        FD_ISEDITABLE,    // FIELD_putIdClientSide
        FD_ISEDITABLE,    // FIELD_clientId
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *AbortMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "key",
        "putIdClientSide",
        "clientId",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int AbortMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "key") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "putIdClientSide") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "clientId") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *AbortMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_key
        "int",    // FIELD_putIdClientSide
        "int",    // FIELD_clientId
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **AbortMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *AbortMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int AbortMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    AbortMessage *pp = omnetpp::fromAnyPtr<AbortMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void AbortMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    AbortMessage *pp = omnetpp::fromAnyPtr<AbortMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'AbortMessage'", field);
    }
}

const char *AbortMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    AbortMessage *pp = omnetpp::fromAnyPtr<AbortMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AbortMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    AbortMessage *pp = omnetpp::fromAnyPtr<AbortMessage>(object); (void)pp;
    switch (field) {
        case FIELD_key: return long2string(pp->getKey());
        case FIELD_putIdClientSide: return long2string(pp->getPutIdClientSide());
        case FIELD_clientId: return long2string(pp->getClientId());
        default: return "";
    }
}

void AbortMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AbortMessage *pp = omnetpp::fromAnyPtr<AbortMessage>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(string2long(value)); break;
        case FIELD_putIdClientSide: pp->setPutIdClientSide(string2long(value)); break;
        case FIELD_clientId: pp->setClientId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AbortMessage'", field);
    }
}

omnetpp::cValue AbortMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    AbortMessage *pp = omnetpp::fromAnyPtr<AbortMessage>(object); (void)pp;
    switch (field) {
        case FIELD_key: return pp->getKey();
        case FIELD_putIdClientSide: return pp->getPutIdClientSide();
        case FIELD_clientId: return pp->getClientId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'AbortMessage' as cValue -- field index out of range?", field);
    }
}

void AbortMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AbortMessage *pp = omnetpp::fromAnyPtr<AbortMessage>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_putIdClientSide: pp->setPutIdClientSide(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_clientId: pp->setClientId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AbortMessage'", field);
    }
}

const char *AbortMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr AbortMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    AbortMessage *pp = omnetpp::fromAnyPtr<AbortMessage>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void AbortMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    AbortMessage *pp = omnetpp::fromAnyPtr<AbortMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AbortMessage'", field);
    }
}

Register_Class(AbortMessageToClient)

AbortMessageToClient::AbortMessageToClient(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

AbortMessageToClient::AbortMessageToClient(const AbortMessageToClient& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

AbortMessageToClient::~AbortMessageToClient()
{
}

AbortMessageToClient& AbortMessageToClient::operator=(const AbortMessageToClient& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void AbortMessageToClient::copy(const AbortMessageToClient& other)
{
    this->key = other.key;
    this->putIdClientSide = other.putIdClientSide;
}

void AbortMessageToClient::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->key);
    doParsimPacking(b,this->putIdClientSide);
}

void AbortMessageToClient::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->key);
    doParsimUnpacking(b,this->putIdClientSide);
}

int AbortMessageToClient::getKey() const
{
    return this->key;
}

void AbortMessageToClient::setKey(int key)
{
    this->key = key;
}

int AbortMessageToClient::getPutIdClientSide() const
{
    return this->putIdClientSide;
}

void AbortMessageToClient::setPutIdClientSide(int putIdClientSide)
{
    this->putIdClientSide = putIdClientSide;
}

class AbortMessageToClientDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_key,
        FIELD_putIdClientSide,
    };
  public:
    AbortMessageToClientDescriptor();
    virtual ~AbortMessageToClientDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(AbortMessageToClientDescriptor)

AbortMessageToClientDescriptor::AbortMessageToClientDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(AbortMessageToClient)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

AbortMessageToClientDescriptor::~AbortMessageToClientDescriptor()
{
    delete[] propertyNames;
}

bool AbortMessageToClientDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<AbortMessageToClient *>(obj)!=nullptr;
}

const char **AbortMessageToClientDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *AbortMessageToClientDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int AbortMessageToClientDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int AbortMessageToClientDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_key
        FD_ISEDITABLE,    // FIELD_putIdClientSide
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *AbortMessageToClientDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "key",
        "putIdClientSide",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int AbortMessageToClientDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "key") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "putIdClientSide") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *AbortMessageToClientDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_key
        "int",    // FIELD_putIdClientSide
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **AbortMessageToClientDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *AbortMessageToClientDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int AbortMessageToClientDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    AbortMessageToClient *pp = omnetpp::fromAnyPtr<AbortMessageToClient>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void AbortMessageToClientDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    AbortMessageToClient *pp = omnetpp::fromAnyPtr<AbortMessageToClient>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'AbortMessageToClient'", field);
    }
}

const char *AbortMessageToClientDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    AbortMessageToClient *pp = omnetpp::fromAnyPtr<AbortMessageToClient>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string AbortMessageToClientDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    AbortMessageToClient *pp = omnetpp::fromAnyPtr<AbortMessageToClient>(object); (void)pp;
    switch (field) {
        case FIELD_key: return long2string(pp->getKey());
        case FIELD_putIdClientSide: return long2string(pp->getPutIdClientSide());
        default: return "";
    }
}

void AbortMessageToClientDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AbortMessageToClient *pp = omnetpp::fromAnyPtr<AbortMessageToClient>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(string2long(value)); break;
        case FIELD_putIdClientSide: pp->setPutIdClientSide(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AbortMessageToClient'", field);
    }
}

omnetpp::cValue AbortMessageToClientDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    AbortMessageToClient *pp = omnetpp::fromAnyPtr<AbortMessageToClient>(object); (void)pp;
    switch (field) {
        case FIELD_key: return pp->getKey();
        case FIELD_putIdClientSide: return pp->getPutIdClientSide();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'AbortMessageToClient' as cValue -- field index out of range?", field);
    }
}

void AbortMessageToClientDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    AbortMessageToClient *pp = omnetpp::fromAnyPtr<AbortMessageToClient>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_putIdClientSide: pp->setPutIdClientSide(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AbortMessageToClient'", field);
    }
}

const char *AbortMessageToClientDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr AbortMessageToClientDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    AbortMessageToClient *pp = omnetpp::fromAnyPtr<AbortMessageToClient>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void AbortMessageToClientDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    AbortMessageToClient *pp = omnetpp::fromAnyPtr<AbortMessageToClient>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'AbortMessageToClient'", field);
    }
}

Register_Class(CommitMessageToClient)

CommitMessageToClient::CommitMessageToClient(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

CommitMessageToClient::CommitMessageToClient(const CommitMessageToClient& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

CommitMessageToClient::~CommitMessageToClient()
{
}

CommitMessageToClient& CommitMessageToClient::operator=(const CommitMessageToClient& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void CommitMessageToClient::copy(const CommitMessageToClient& other)
{
    this->key = other.key;
    this->putIdClientSide = other.putIdClientSide;
}

void CommitMessageToClient::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->key);
    doParsimPacking(b,this->putIdClientSide);
}

void CommitMessageToClient::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->key);
    doParsimUnpacking(b,this->putIdClientSide);
}

int CommitMessageToClient::getKey() const
{
    return this->key;
}

void CommitMessageToClient::setKey(int key)
{
    this->key = key;
}

int CommitMessageToClient::getPutIdClientSide() const
{
    return this->putIdClientSide;
}

void CommitMessageToClient::setPutIdClientSide(int putIdClientSide)
{
    this->putIdClientSide = putIdClientSide;
}

class CommitMessageToClientDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_key,
        FIELD_putIdClientSide,
    };
  public:
    CommitMessageToClientDescriptor();
    virtual ~CommitMessageToClientDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(CommitMessageToClientDescriptor)

CommitMessageToClientDescriptor::CommitMessageToClientDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(CommitMessageToClient)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

CommitMessageToClientDescriptor::~CommitMessageToClientDescriptor()
{
    delete[] propertyNames;
}

bool CommitMessageToClientDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CommitMessageToClient *>(obj)!=nullptr;
}

const char **CommitMessageToClientDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *CommitMessageToClientDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int CommitMessageToClientDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int CommitMessageToClientDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_key
        FD_ISEDITABLE,    // FIELD_putIdClientSide
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *CommitMessageToClientDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "key",
        "putIdClientSide",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int CommitMessageToClientDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "key") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "putIdClientSide") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *CommitMessageToClientDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_key
        "int",    // FIELD_putIdClientSide
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **CommitMessageToClientDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *CommitMessageToClientDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int CommitMessageToClientDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    CommitMessageToClient *pp = omnetpp::fromAnyPtr<CommitMessageToClient>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void CommitMessageToClientDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    CommitMessageToClient *pp = omnetpp::fromAnyPtr<CommitMessageToClient>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'CommitMessageToClient'", field);
    }
}

const char *CommitMessageToClientDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    CommitMessageToClient *pp = omnetpp::fromAnyPtr<CommitMessageToClient>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CommitMessageToClientDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    CommitMessageToClient *pp = omnetpp::fromAnyPtr<CommitMessageToClient>(object); (void)pp;
    switch (field) {
        case FIELD_key: return long2string(pp->getKey());
        case FIELD_putIdClientSide: return long2string(pp->getPutIdClientSide());
        default: return "";
    }
}

void CommitMessageToClientDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CommitMessageToClient *pp = omnetpp::fromAnyPtr<CommitMessageToClient>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(string2long(value)); break;
        case FIELD_putIdClientSide: pp->setPutIdClientSide(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CommitMessageToClient'", field);
    }
}

omnetpp::cValue CommitMessageToClientDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    CommitMessageToClient *pp = omnetpp::fromAnyPtr<CommitMessageToClient>(object); (void)pp;
    switch (field) {
        case FIELD_key: return pp->getKey();
        case FIELD_putIdClientSide: return pp->getPutIdClientSide();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'CommitMessageToClient' as cValue -- field index out of range?", field);
    }
}

void CommitMessageToClientDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CommitMessageToClient *pp = omnetpp::fromAnyPtr<CommitMessageToClient>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_putIdClientSide: pp->setPutIdClientSide(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CommitMessageToClient'", field);
    }
}

const char *CommitMessageToClientDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr CommitMessageToClientDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    CommitMessageToClient *pp = omnetpp::fromAnyPtr<CommitMessageToClient>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void CommitMessageToClientDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    CommitMessageToClient *pp = omnetpp::fromAnyPtr<CommitMessageToClient>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CommitMessageToClient'", field);
    }
}

Register_Class(UpdateRequest)

UpdateRequest::UpdateRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

UpdateRequest::UpdateRequest(const UpdateRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

UpdateRequest::~UpdateRequest()
{
}

UpdateRequest& UpdateRequest::operator=(const UpdateRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void UpdateRequest::copy(const UpdateRequest& other)
{
    this->key = other.key;
    this->putIdClientSide = other.putIdClientSide;
    this->clientId = other.clientId;
}

void UpdateRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->key);
    doParsimPacking(b,this->putIdClientSide);
    doParsimPacking(b,this->clientId);
}

void UpdateRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->key);
    doParsimUnpacking(b,this->putIdClientSide);
    doParsimUnpacking(b,this->clientId);
}

int UpdateRequest::getKey() const
{
    return this->key;
}

void UpdateRequest::setKey(int key)
{
    this->key = key;
}

int UpdateRequest::getPutIdClientSide() const
{
    return this->putIdClientSide;
}

void UpdateRequest::setPutIdClientSide(int putIdClientSide)
{
    this->putIdClientSide = putIdClientSide;
}

int UpdateRequest::getClientId() const
{
    return this->clientId;
}

void UpdateRequest::setClientId(int clientId)
{
    this->clientId = clientId;
}

class UpdateRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_key,
        FIELD_putIdClientSide,
        FIELD_clientId,
    };
  public:
    UpdateRequestDescriptor();
    virtual ~UpdateRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(UpdateRequestDescriptor)

UpdateRequestDescriptor::UpdateRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(UpdateRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

UpdateRequestDescriptor::~UpdateRequestDescriptor()
{
    delete[] propertyNames;
}

bool UpdateRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UpdateRequest *>(obj)!=nullptr;
}

const char **UpdateRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *UpdateRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int UpdateRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int UpdateRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_key
        FD_ISEDITABLE,    // FIELD_putIdClientSide
        FD_ISEDITABLE,    // FIELD_clientId
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *UpdateRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "key",
        "putIdClientSide",
        "clientId",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int UpdateRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "key") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "putIdClientSide") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "clientId") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *UpdateRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_key
        "int",    // FIELD_putIdClientSide
        "int",    // FIELD_clientId
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **UpdateRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *UpdateRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int UpdateRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    UpdateRequest *pp = omnetpp::fromAnyPtr<UpdateRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void UpdateRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    UpdateRequest *pp = omnetpp::fromAnyPtr<UpdateRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'UpdateRequest'", field);
    }
}

const char *UpdateRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    UpdateRequest *pp = omnetpp::fromAnyPtr<UpdateRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UpdateRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    UpdateRequest *pp = omnetpp::fromAnyPtr<UpdateRequest>(object); (void)pp;
    switch (field) {
        case FIELD_key: return long2string(pp->getKey());
        case FIELD_putIdClientSide: return long2string(pp->getPutIdClientSide());
        case FIELD_clientId: return long2string(pp->getClientId());
        default: return "";
    }
}

void UpdateRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UpdateRequest *pp = omnetpp::fromAnyPtr<UpdateRequest>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(string2long(value)); break;
        case FIELD_putIdClientSide: pp->setPutIdClientSide(string2long(value)); break;
        case FIELD_clientId: pp->setClientId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UpdateRequest'", field);
    }
}

omnetpp::cValue UpdateRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    UpdateRequest *pp = omnetpp::fromAnyPtr<UpdateRequest>(object); (void)pp;
    switch (field) {
        case FIELD_key: return pp->getKey();
        case FIELD_putIdClientSide: return pp->getPutIdClientSide();
        case FIELD_clientId: return pp->getClientId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'UpdateRequest' as cValue -- field index out of range?", field);
    }
}

void UpdateRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UpdateRequest *pp = omnetpp::fromAnyPtr<UpdateRequest>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_putIdClientSide: pp->setPutIdClientSide(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_clientId: pp->setClientId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UpdateRequest'", field);
    }
}

const char *UpdateRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr UpdateRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    UpdateRequest *pp = omnetpp::fromAnyPtr<UpdateRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void UpdateRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    UpdateRequest *pp = omnetpp::fromAnyPtr<UpdateRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UpdateRequest'", field);
    }
}

Register_Class(UpdateResponse)

UpdateResponse::UpdateResponse(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

UpdateResponse::UpdateResponse(const UpdateResponse& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

UpdateResponse::~UpdateResponse()
{
}

UpdateResponse& UpdateResponse::operator=(const UpdateResponse& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void UpdateResponse::copy(const UpdateResponse& other)
{
    this->key = other.key;
    this->version = other.version;
    this->abortRequest = other.abortRequest;
}

void UpdateResponse::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->key);
    doParsimPacking(b,this->version);
    doParsimPacking(b,this->abortRequest);
}

void UpdateResponse::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->key);
    doParsimUnpacking(b,this->version);
    doParsimUnpacking(b,this->abortRequest);
}

int UpdateResponse::getKey() const
{
    return this->key;
}

void UpdateResponse::setKey(int key)
{
    this->key = key;
}

int UpdateResponse::getVersion() const
{
    return this->version;
}

void UpdateResponse::setVersion(int version)
{
    this->version = version;
}

bool UpdateResponse::getAbortRequest() const
{
    return this->abortRequest;
}

void UpdateResponse::setAbortRequest(bool abortRequest)
{
    this->abortRequest = abortRequest;
}

class UpdateResponseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_key,
        FIELD_version,
        FIELD_abortRequest,
    };
  public:
    UpdateResponseDescriptor();
    virtual ~UpdateResponseDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(UpdateResponseDescriptor)

UpdateResponseDescriptor::UpdateResponseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(UpdateResponse)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

UpdateResponseDescriptor::~UpdateResponseDescriptor()
{
    delete[] propertyNames;
}

bool UpdateResponseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UpdateResponse *>(obj)!=nullptr;
}

const char **UpdateResponseDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *UpdateResponseDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int UpdateResponseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int UpdateResponseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_key
        FD_ISEDITABLE,    // FIELD_version
        FD_ISEDITABLE,    // FIELD_abortRequest
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *UpdateResponseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "key",
        "version",
        "abortRequest",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int UpdateResponseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "key") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "version") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "abortRequest") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *UpdateResponseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_key
        "int",    // FIELD_version
        "bool",    // FIELD_abortRequest
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **UpdateResponseDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *UpdateResponseDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int UpdateResponseDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    UpdateResponse *pp = omnetpp::fromAnyPtr<UpdateResponse>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void UpdateResponseDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    UpdateResponse *pp = omnetpp::fromAnyPtr<UpdateResponse>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'UpdateResponse'", field);
    }
}

const char *UpdateResponseDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    UpdateResponse *pp = omnetpp::fromAnyPtr<UpdateResponse>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UpdateResponseDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    UpdateResponse *pp = omnetpp::fromAnyPtr<UpdateResponse>(object); (void)pp;
    switch (field) {
        case FIELD_key: return long2string(pp->getKey());
        case FIELD_version: return long2string(pp->getVersion());
        case FIELD_abortRequest: return bool2string(pp->getAbortRequest());
        default: return "";
    }
}

void UpdateResponseDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UpdateResponse *pp = omnetpp::fromAnyPtr<UpdateResponse>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(string2long(value)); break;
        case FIELD_version: pp->setVersion(string2long(value)); break;
        case FIELD_abortRequest: pp->setAbortRequest(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UpdateResponse'", field);
    }
}

omnetpp::cValue UpdateResponseDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    UpdateResponse *pp = omnetpp::fromAnyPtr<UpdateResponse>(object); (void)pp;
    switch (field) {
        case FIELD_key: return pp->getKey();
        case FIELD_version: return pp->getVersion();
        case FIELD_abortRequest: return pp->getAbortRequest();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'UpdateResponse' as cValue -- field index out of range?", field);
    }
}

void UpdateResponseDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    UpdateResponse *pp = omnetpp::fromAnyPtr<UpdateResponse>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_version: pp->setVersion(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_abortRequest: pp->setAbortRequest(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UpdateResponse'", field);
    }
}

const char *UpdateResponseDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr UpdateResponseDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    UpdateResponse *pp = omnetpp::fromAnyPtr<UpdateResponse>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void UpdateResponseDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    UpdateResponse *pp = omnetpp::fromAnyPtr<UpdateResponse>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'UpdateResponse'", field);
    }
}

Register_Class(GetRequest)

GetRequest::GetRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

GetRequest::GetRequest(const GetRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

GetRequest::~GetRequest()
{
}

GetRequest& GetRequest::operator=(const GetRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void GetRequest::copy(const GetRequest& other)
{
    this->readQuorum = other.readQuorum;
    this->key = other.key;
    this->readIdClientSide = other.readIdClientSide;
}

void GetRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->readQuorum);
    doParsimPacking(b,this->key);
    doParsimPacking(b,this->readIdClientSide);
}

void GetRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->readQuorum);
    doParsimUnpacking(b,this->key);
    doParsimUnpacking(b,this->readIdClientSide);
}

const Vector& GetRequest::getReadQuorum() const
{
    return this->readQuorum;
}

void GetRequest::setReadQuorum(const Vector& readQuorum)
{
    this->readQuorum = readQuorum;
}

int GetRequest::getKey() const
{
    return this->key;
}

void GetRequest::setKey(int key)
{
    this->key = key;
}

int GetRequest::getReadIdClientSide() const
{
    return this->readIdClientSide;
}

void GetRequest::setReadIdClientSide(int readIdClientSide)
{
    this->readIdClientSide = readIdClientSide;
}

class GetRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_readQuorum,
        FIELD_key,
        FIELD_readIdClientSide,
    };
  public:
    GetRequestDescriptor();
    virtual ~GetRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(GetRequestDescriptor)

GetRequestDescriptor::GetRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(GetRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

GetRequestDescriptor::~GetRequestDescriptor()
{
    delete[] propertyNames;
}

bool GetRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<GetRequest *>(obj)!=nullptr;
}

const char **GetRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *GetRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int GetRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int GetRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_readQuorum
        FD_ISEDITABLE,    // FIELD_key
        FD_ISEDITABLE,    // FIELD_readIdClientSide
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *GetRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "readQuorum",
        "key",
        "readIdClientSide",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int GetRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "readQuorum") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "key") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "readIdClientSide") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *GetRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Vector",    // FIELD_readQuorum
        "int",    // FIELD_key
        "int",    // FIELD_readIdClientSide
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **GetRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *GetRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int GetRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    GetRequest *pp = omnetpp::fromAnyPtr<GetRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void GetRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    GetRequest *pp = omnetpp::fromAnyPtr<GetRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'GetRequest'", field);
    }
}

const char *GetRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    GetRequest *pp = omnetpp::fromAnyPtr<GetRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string GetRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    GetRequest *pp = omnetpp::fromAnyPtr<GetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_readQuorum: return "";
        case FIELD_key: return long2string(pp->getKey());
        case FIELD_readIdClientSide: return long2string(pp->getReadIdClientSide());
        default: return "";
    }
}

void GetRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    GetRequest *pp = omnetpp::fromAnyPtr<GetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(string2long(value)); break;
        case FIELD_readIdClientSide: pp->setReadIdClientSide(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'GetRequest'", field);
    }
}

omnetpp::cValue GetRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    GetRequest *pp = omnetpp::fromAnyPtr<GetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_readQuorum: return omnetpp::toAnyPtr(&pp->getReadQuorum()); break;
        case FIELD_key: return pp->getKey();
        case FIELD_readIdClientSide: return pp->getReadIdClientSide();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'GetRequest' as cValue -- field index out of range?", field);
    }
}

void GetRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    GetRequest *pp = omnetpp::fromAnyPtr<GetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_readIdClientSide: pp->setReadIdClientSide(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'GetRequest'", field);
    }
}

const char *GetRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_readQuorum: return omnetpp::opp_typename(typeid(Vector));
        default: return nullptr;
    };
}

omnetpp::any_ptr GetRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    GetRequest *pp = omnetpp::fromAnyPtr<GetRequest>(object); (void)pp;
    switch (field) {
        case FIELD_readQuorum: return omnetpp::toAnyPtr(&pp->getReadQuorum()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void GetRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    GetRequest *pp = omnetpp::fromAnyPtr<GetRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'GetRequest'", field);
    }
}

Register_Class(ValueRequest)

ValueRequest::ValueRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

ValueRequest::ValueRequest(const ValueRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

ValueRequest::~ValueRequest()
{
}

ValueRequest& ValueRequest::operator=(const ValueRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void ValueRequest::copy(const ValueRequest& other)
{
    this->key = other.key;
    this->readId = other.readId;
}

void ValueRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->key);
    doParsimPacking(b,this->readId);
}

void ValueRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->key);
    doParsimUnpacking(b,this->readId);
}

int ValueRequest::getKey() const
{
    return this->key;
}

void ValueRequest::setKey(int key)
{
    this->key = key;
}

int ValueRequest::getReadId() const
{
    return this->readId;
}

void ValueRequest::setReadId(int readId)
{
    this->readId = readId;
}

class ValueRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_key,
        FIELD_readId,
    };
  public:
    ValueRequestDescriptor();
    virtual ~ValueRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(ValueRequestDescriptor)

ValueRequestDescriptor::ValueRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(ValueRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

ValueRequestDescriptor::~ValueRequestDescriptor()
{
    delete[] propertyNames;
}

bool ValueRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ValueRequest *>(obj)!=nullptr;
}

const char **ValueRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *ValueRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int ValueRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int ValueRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_key
        FD_ISEDITABLE,    // FIELD_readId
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *ValueRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "key",
        "readId",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int ValueRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "key") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "readId") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *ValueRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_key
        "int",    // FIELD_readId
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **ValueRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ValueRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ValueRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    ValueRequest *pp = omnetpp::fromAnyPtr<ValueRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ValueRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    ValueRequest *pp = omnetpp::fromAnyPtr<ValueRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ValueRequest'", field);
    }
}

const char *ValueRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    ValueRequest *pp = omnetpp::fromAnyPtr<ValueRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ValueRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    ValueRequest *pp = omnetpp::fromAnyPtr<ValueRequest>(object); (void)pp;
    switch (field) {
        case FIELD_key: return long2string(pp->getKey());
        case FIELD_readId: return long2string(pp->getReadId());
        default: return "";
    }
}

void ValueRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ValueRequest *pp = omnetpp::fromAnyPtr<ValueRequest>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(string2long(value)); break;
        case FIELD_readId: pp->setReadId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ValueRequest'", field);
    }
}

omnetpp::cValue ValueRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    ValueRequest *pp = omnetpp::fromAnyPtr<ValueRequest>(object); (void)pp;
    switch (field) {
        case FIELD_key: return pp->getKey();
        case FIELD_readId: return pp->getReadId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'ValueRequest' as cValue -- field index out of range?", field);
    }
}

void ValueRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ValueRequest *pp = omnetpp::fromAnyPtr<ValueRequest>(object); (void)pp;
    switch (field) {
        case FIELD_key: pp->setKey(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_readId: pp->setReadId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ValueRequest'", field);
    }
}

const char *ValueRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr ValueRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    ValueRequest *pp = omnetpp::fromAnyPtr<ValueRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void ValueRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    ValueRequest *pp = omnetpp::fromAnyPtr<ValueRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ValueRequest'", field);
    }
}

Register_Class(ValueResponse)

ValueResponse::ValueResponse(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

ValueResponse::ValueResponse(const ValueResponse& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

ValueResponse::~ValueResponse()
{
}

ValueResponse& ValueResponse::operator=(const ValueResponse& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void ValueResponse::copy(const ValueResponse& other)
{
    this->keyValueItem = other.keyValueItem;
    this->readId = other.readId;
}

void ValueResponse::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->keyValueItem);
    doParsimPacking(b,this->readId);
}

void ValueResponse::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->keyValueItem);
    doParsimUnpacking(b,this->readId);
}

const DataItem& ValueResponse::getKeyValueItem() const
{
    return this->keyValueItem;
}

void ValueResponse::setKeyValueItem(const DataItem& keyValueItem)
{
    this->keyValueItem = keyValueItem;
}

int ValueResponse::getReadId() const
{
    return this->readId;
}

void ValueResponse::setReadId(int readId)
{
    this->readId = readId;
}

class ValueResponseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_keyValueItem,
        FIELD_readId,
    };
  public:
    ValueResponseDescriptor();
    virtual ~ValueResponseDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(ValueResponseDescriptor)

ValueResponseDescriptor::ValueResponseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(ValueResponse)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

ValueResponseDescriptor::~ValueResponseDescriptor()
{
    delete[] propertyNames;
}

bool ValueResponseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ValueResponse *>(obj)!=nullptr;
}

const char **ValueResponseDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *ValueResponseDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int ValueResponseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int ValueResponseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_keyValueItem
        FD_ISEDITABLE,    // FIELD_readId
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *ValueResponseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "keyValueItem",
        "readId",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int ValueResponseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "keyValueItem") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "readId") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *ValueResponseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "DataItem",    // FIELD_keyValueItem
        "int",    // FIELD_readId
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **ValueResponseDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ValueResponseDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ValueResponseDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    ValueResponse *pp = omnetpp::fromAnyPtr<ValueResponse>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ValueResponseDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    ValueResponse *pp = omnetpp::fromAnyPtr<ValueResponse>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ValueResponse'", field);
    }
}

const char *ValueResponseDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    ValueResponse *pp = omnetpp::fromAnyPtr<ValueResponse>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ValueResponseDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    ValueResponse *pp = omnetpp::fromAnyPtr<ValueResponse>(object); (void)pp;
    switch (field) {
        case FIELD_keyValueItem: return "";
        case FIELD_readId: return long2string(pp->getReadId());
        default: return "";
    }
}

void ValueResponseDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ValueResponse *pp = omnetpp::fromAnyPtr<ValueResponse>(object); (void)pp;
    switch (field) {
        case FIELD_readId: pp->setReadId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ValueResponse'", field);
    }
}

omnetpp::cValue ValueResponseDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    ValueResponse *pp = omnetpp::fromAnyPtr<ValueResponse>(object); (void)pp;
    switch (field) {
        case FIELD_keyValueItem: return omnetpp::toAnyPtr(&pp->getKeyValueItem()); break;
        case FIELD_readId: return pp->getReadId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'ValueResponse' as cValue -- field index out of range?", field);
    }
}

void ValueResponseDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ValueResponse *pp = omnetpp::fromAnyPtr<ValueResponse>(object); (void)pp;
    switch (field) {
        case FIELD_readId: pp->setReadId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ValueResponse'", field);
    }
}

const char *ValueResponseDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_keyValueItem: return omnetpp::opp_typename(typeid(DataItem));
        default: return nullptr;
    };
}

omnetpp::any_ptr ValueResponseDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    ValueResponse *pp = omnetpp::fromAnyPtr<ValueResponse>(object); (void)pp;
    switch (field) {
        case FIELD_keyValueItem: return omnetpp::toAnyPtr(&pp->getKeyValueItem()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void ValueResponseDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    ValueResponse *pp = omnetpp::fromAnyPtr<ValueResponse>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ValueResponse'", field);
    }
}

Register_Class(GetResponse)

GetResponse::GetResponse(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

GetResponse::GetResponse(const GetResponse& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

GetResponse::~GetResponse()
{
}

GetResponse& GetResponse::operator=(const GetResponse& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void GetResponse::copy(const GetResponse& other)
{
    this->keyValueItem = other.keyValueItem;
    this->readIdClientSide = other.readIdClientSide;
}

void GetResponse::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->keyValueItem);
    doParsimPacking(b,this->readIdClientSide);
}

void GetResponse::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->keyValueItem);
    doParsimUnpacking(b,this->readIdClientSide);
}

const DataItem& GetResponse::getKeyValueItem() const
{
    return this->keyValueItem;
}

void GetResponse::setKeyValueItem(const DataItem& keyValueItem)
{
    this->keyValueItem = keyValueItem;
}

int GetResponse::getReadIdClientSide() const
{
    return this->readIdClientSide;
}

void GetResponse::setReadIdClientSide(int readIdClientSide)
{
    this->readIdClientSide = readIdClientSide;
}

class GetResponseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_keyValueItem,
        FIELD_readIdClientSide,
    };
  public:
    GetResponseDescriptor();
    virtual ~GetResponseDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(GetResponseDescriptor)

GetResponseDescriptor::GetResponseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(GetResponse)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

GetResponseDescriptor::~GetResponseDescriptor()
{
    delete[] propertyNames;
}

bool GetResponseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<GetResponse *>(obj)!=nullptr;
}

const char **GetResponseDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *GetResponseDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int GetResponseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int GetResponseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,    // FIELD_keyValueItem
        FD_ISEDITABLE,    // FIELD_readIdClientSide
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *GetResponseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "keyValueItem",
        "readIdClientSide",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int GetResponseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "keyValueItem") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "readIdClientSide") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *GetResponseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "DataItem",    // FIELD_keyValueItem
        "int",    // FIELD_readIdClientSide
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **GetResponseDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *GetResponseDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int GetResponseDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    GetResponse *pp = omnetpp::fromAnyPtr<GetResponse>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void GetResponseDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    GetResponse *pp = omnetpp::fromAnyPtr<GetResponse>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'GetResponse'", field);
    }
}

const char *GetResponseDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    GetResponse *pp = omnetpp::fromAnyPtr<GetResponse>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string GetResponseDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    GetResponse *pp = omnetpp::fromAnyPtr<GetResponse>(object); (void)pp;
    switch (field) {
        case FIELD_keyValueItem: return "";
        case FIELD_readIdClientSide: return long2string(pp->getReadIdClientSide());
        default: return "";
    }
}

void GetResponseDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    GetResponse *pp = omnetpp::fromAnyPtr<GetResponse>(object); (void)pp;
    switch (field) {
        case FIELD_readIdClientSide: pp->setReadIdClientSide(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'GetResponse'", field);
    }
}

omnetpp::cValue GetResponseDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    GetResponse *pp = omnetpp::fromAnyPtr<GetResponse>(object); (void)pp;
    switch (field) {
        case FIELD_keyValueItem: return omnetpp::toAnyPtr(&pp->getKeyValueItem()); break;
        case FIELD_readIdClientSide: return pp->getReadIdClientSide();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'GetResponse' as cValue -- field index out of range?", field);
    }
}

void GetResponseDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    GetResponse *pp = omnetpp::fromAnyPtr<GetResponse>(object); (void)pp;
    switch (field) {
        case FIELD_readIdClientSide: pp->setReadIdClientSide(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'GetResponse'", field);
    }
}

const char *GetResponseDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_keyValueItem: return omnetpp::opp_typename(typeid(DataItem));
        default: return nullptr;
    };
}

omnetpp::any_ptr GetResponseDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    GetResponse *pp = omnetpp::fromAnyPtr<GetResponse>(object); (void)pp;
    switch (field) {
        case FIELD_keyValueItem: return omnetpp::toAnyPtr(&pp->getKeyValueItem()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void GetResponseDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    GetResponse *pp = omnetpp::fromAnyPtr<GetResponse>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'GetResponse'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

