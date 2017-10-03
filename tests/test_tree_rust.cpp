/* generated by rust_qt_binding_generator */
#include "test_tree_rust.h"

namespace {

    struct option_quintptr {
    public:
        quintptr value;
        bool some;
        operator QVariant() const {
            if (some) {
                return QVariant(value);
            }
            return QVariant();
        }
    };

    struct qstring_t {
    private:
        const void* data;
        int len;
    public:
        qstring_t(const QString& v):
            data(static_cast<const void*>(v.utf16())),
            len(v.size()) {
        }
        operator QString() const {
            return QString::fromUtf8(static_cast<const char*>(data), len);
        }
    };
    typedef void (*qstring_set)(QString*, qstring_t*);
    void set_qstring(QString* v, qstring_t* val) {
        *v = *val;
    }

    struct qmodelindex_t {
        int row;
        quintptr id;
    };
}
extern "C" {
    void persons_data_user_name(const Persons::Private*, quintptr, QString*, qstring_set);
    bool persons_set_data_user_name(Persons::Private*, quintptr, qstring_t);
    void persons_sort(Persons::Private*, unsigned char column, Qt::SortOrder order = Qt::AscendingOrder);

    int persons_row_count(const Persons::Private*, quintptr, bool);
    bool persons_can_fetch_more(const Persons::Private*, quintptr, bool);
    void persons_fetch_more(Persons::Private*, quintptr, bool);
    quintptr persons_index(const Persons::Private*, quintptr, bool, int);
    qmodelindex_t persons_parent(const Persons::Private*, quintptr);
    int persons_row(const Persons::Private*, quintptr);
}
int Persons::columnCount(const QModelIndex &) const
{
    return 1;
}

bool Persons::hasChildren(const QModelIndex &parent) const
{
    return rowCount(parent) > 0;
}

int Persons::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0) {
        return 0;
    }
    return persons_row_count(m_d, parent.internalId(), parent.isValid());
}

bool Persons::insertRows(int, int, const QModelIndex &)
{
    return false; // not supported yet
}

bool Persons::removeRows(int, int, const QModelIndex &)
{
    return false; // not supported yet
}

QModelIndex Persons::index(int row, int column, const QModelIndex &parent) const
{
    if (row < 0 || column < 0 || column >= 1) {
        return QModelIndex();
    }
    if (parent.isValid() && parent.column() != 0) {
        return QModelIndex();
    }
    if (row >= rowCount(parent)) {
        return QModelIndex();
    }
    const quintptr id = persons_index(m_d, parent.internalId(), parent.isValid(), row);
    return createIndex(row, column, id);
}

QModelIndex Persons::parent(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return QModelIndex();
    }
    const qmodelindex_t parent = persons_parent(m_d, index.internalId());
    return parent.row >= 0 ?createIndex(parent.row, 0, parent.id) :QModelIndex();
}

bool Persons::canFetchMore(const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0) {
        return false;
    }
    return persons_can_fetch_more(m_d, parent.internalId(), parent.isValid());
}

void Persons::fetchMore(const QModelIndex &parent)
{
    persons_fetch_more(m_d, parent.internalId(), parent.isValid());
}

void Persons::sort(int column, Qt::SortOrder order)
{
    persons_sort(m_d, column, order);
}
Qt::ItemFlags Persons::flags(const QModelIndex &i) const
{
    auto flags = QAbstractItemModel::flags(i);
    if (i.column() == 0) {
        flags |= Qt::ItemIsEditable;
    }
    return flags;
}

QVariant Persons::userName(const QModelIndex& index) const
{
    QVariant v;
    QString s;
    persons_data_user_name(m_d, index.internalId(), &s, set_qstring);
    if (!s.isNull()) v.setValue<QString>(s);
    return v;
}

bool Persons::setUserName(const QModelIndex& index, const QVariant& value)
{
    bool set = false;
    set = persons_set_data_user_name(m_d, index.internalId(), value.value<QString>());
    if (set) {
        emit dataChanged(index, index);
    }
    return set;
}

QVariant Persons::data(const QModelIndex &index, int role) const
{
    Q_ASSERT(rowCount(index.parent()) > index.row());
    switch (index.column()) {
    case 0:
        switch (role) {
        case Qt::DisplayRole:
        case Qt::EditRole:
        case Qt::UserRole + 0:
            return userName(index);
        }
    }
    return QVariant();
}

QHash<int, QByteArray> Persons::roleNames() const {
    QHash<int, QByteArray> names = QAbstractItemModel::roleNames();
    names.insert(Qt::UserRole + 0, "userName");
    return names;
}
QVariant Persons::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal) {
        return QVariant();
    }
    return m_headerData.value(qMakePair(section, (Qt::ItemDataRole)role), role == Qt::DisplayRole ?QString::number(section + 1) :QVariant());
}

bool Persons::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (orientation != Qt::Horizontal) {
        return false;
    }
    m_headerData.insert(qMakePair(section, (Qt::ItemDataRole)role), value);
    return true;
}

bool Persons::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.column() == 0) {
        if (role == Qt::DisplayRole || role == Qt::EditRole || role == Qt::UserRole + 0) {
            return setUserName(index, value);
        }
    }
    return false;
}

extern "C" {
    Persons::Private* persons_new(Persons*,
        void (*)(const Persons*, quintptr, bool),
        void (*)(Persons*, quintptr, quintptr),
        void (*)(Persons*),
        void (*)(Persons*),
        void (*)(Persons*, option_quintptr, int, int),
        void (*)(Persons*),
        void (*)(Persons*, option_quintptr, int, int),
        void (*)(Persons*));
    void persons_free(Persons::Private*);
};

Persons::Persons(bool /*owned*/, QObject *parent):
    QAbstractItemModel(parent),
    m_d(0),
    m_ownsPrivate(false)
{
    initHeaderData();
}

Persons::Persons(QObject *parent):
    QAbstractItemModel(parent),
    m_d(persons_new(this,
        [](const Persons* o, quintptr id, bool valid) {
            if (valid) {
                int row = persons_row(o->m_d, id);
                emit o->newDataReady(o->createIndex(row, 0, id));
            } else {
                emit o->newDataReady(QModelIndex());
            }
        },
        [](Persons* o, quintptr first, quintptr last) {
            quintptr frow = persons_row(o->m_d, first);
            quintptr lrow = persons_row(o->m_d, first);
            o->dataChanged(o->createIndex(frow, 0, first),
                       o->createIndex(lrow, 0, last));
        },
        [](Persons* o) {
            o->beginResetModel();
        },
        [](Persons* o) {
            o->endResetModel();
        },
        [](Persons* o, option_quintptr id, int first, int last) {
            if (id.some) {
                int row = persons_row(o->m_d, id.value);
                o->beginInsertRows(o->createIndex(row, 0, id.value), first, last);
            } else {
                o->beginInsertRows(QModelIndex(), first, last);
            }
        },
        [](Persons* o) {
            o->endInsertRows();
        },
        [](Persons* o, option_quintptr id, int first, int last) {
            if (id.some) {
                int row = persons_row(o->m_d, id.value);
                o->beginRemoveRows(o->createIndex(row, 0, id.value), first, last);
            } else {
                o->beginRemoveRows(QModelIndex(), first, last);
            }
        },
        [](Persons* o) {
            o->endRemoveRows();
        }
)),
    m_ownsPrivate(true)
{
    connect(this, &Persons::newDataReady, this, [this](const QModelIndex& i) {
        this->fetchMore(i);
    }, Qt::QueuedConnection);
    initHeaderData();
}

Persons::~Persons() {
    if (m_ownsPrivate) {
        persons_free(m_d);
    }
}
void Persons::initHeaderData() {
    m_headerData.insert(qMakePair(0, Qt::DisplayRole), QVariant("userName"));
}
