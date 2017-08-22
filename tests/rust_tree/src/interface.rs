/* generated by rust_qt_binding_generator */
#![allow(unknown_lints)]
#![allow(mutex_atomic, needless_pass_by_value)]
#![allow(unused_imports)]
use libc::{c_int, c_void};
use types::*;
use std::sync::{Arc, Mutex};
use std::ptr::null;

use implementation::*;

pub struct PersonsQObject {}

#[derive (Clone)]
pub struct PersonsEmitter {
    qobject: Arc<Mutex<*const PersonsQObject>>,
    new_data_ready: fn(*const PersonsQObject, item: usize, valid: bool),
}

unsafe impl Send for PersonsEmitter {}

impl PersonsEmitter {
    fn clear(&self) {
        *self.qobject.lock().unwrap() = null();
    }
    pub fn new_data_ready(&self, item: Option<usize>) {
        let ptr = *self.qobject.lock().unwrap();
        if !ptr.is_null() {
             (self.new_data_ready)(ptr, item.unwrap_or(13), item.is_some());
        }
    }
}

pub struct PersonsUniformTree {
    qobject: *const PersonsQObject,
    begin_reset_model: fn(*const PersonsQObject),
    end_reset_model: fn(*const PersonsQObject),
    begin_insert_rows: fn(*const PersonsQObject, item: usize, valid: bool, usize, usize),
    end_insert_rows: fn(*const PersonsQObject),
    begin_remove_rows: fn(*const PersonsQObject, item: usize, valid: bool, usize, usize),
    end_remove_rows: fn(*const PersonsQObject),
}

impl PersonsUniformTree {
    pub fn begin_reset_model(&self) {
        (self.begin_reset_model)(self.qobject);
    }
    pub fn end_reset_model(&self) {
        (self.end_reset_model)(self.qobject);
    }
    pub fn begin_insert_rows(&self, item: Option<usize>, first: usize, last: usize) {
        (self.begin_insert_rows)(self.qobject, item.unwrap_or(13), item.is_some(), first, last);
    }
    pub fn end_insert_rows(&self) {
        (self.end_insert_rows)(self.qobject);
    }
    pub fn begin_remove_rows(&self, item: Option<usize>, first: usize, last: usize) {
        (self.begin_remove_rows)(self.qobject, item.unwrap_or(13), item.is_some(), first, last);
    }
    pub fn end_remove_rows(&self) {
        (self.end_remove_rows)(self.qobject);
    }
}

pub trait PersonsTrait {
    fn create(emit: PersonsEmitter, model: PersonsUniformTree) -> Self;
    fn emit(&self) -> &PersonsEmitter;
    fn row_count(&self, Option<usize>) -> usize;
    fn can_fetch_more(&self, Option<usize>) -> bool { false }
    fn fetch_more(&mut self, Option<usize>) {}
    fn sort(&mut self, u8, SortOrder) {}
    fn index(&self, item: Option<usize>, row: usize) -> usize;
    fn parent(&self, item: usize) -> Option<usize>;
    fn row(&self, item: usize) -> usize;
    fn user_name(&self, item: usize) -> String;
    fn set_user_name(&mut self, item: usize, String) -> bool;
}

#[no_mangle]
pub extern "C" fn persons_new(qobject: *const PersonsQObject,
        new_data_ready: fn(*const PersonsQObject, item: usize, valid: bool),
        begin_reset_model: fn(*const PersonsQObject),
        end_reset_model: fn(*const PersonsQObject),
        begin_insert_rows: fn(*const PersonsQObject, item: usize, valid: bool,
            usize,
            usize),
        end_insert_rows: fn(*const PersonsQObject),
        begin_remove_rows: fn(*const PersonsQObject, item: usize, valid: bool,
            usize,
            usize),
        end_remove_rows: fn(*const PersonsQObject))
        -> *mut Persons {
    let emit = PersonsEmitter {
        qobject: Arc::new(Mutex::new(qobject)),
        new_data_ready: new_data_ready,
    };
    let model = PersonsUniformTree {
        qobject: qobject,
        begin_reset_model: begin_reset_model,
        end_reset_model: end_reset_model,
        begin_insert_rows: begin_insert_rows,
        end_insert_rows: end_insert_rows,
        begin_remove_rows: begin_remove_rows,
        end_remove_rows: end_remove_rows,
    };
    let d = Persons::create(emit, model);
    Box::into_raw(Box::new(d))
}

#[no_mangle]
pub unsafe extern "C" fn persons_free(ptr: *mut Persons) {
    Box::from_raw(ptr).emit().clear();
}

#[no_mangle]
pub unsafe extern "C" fn persons_row_count(ptr: *const Persons, item: usize, valid: bool) -> c_int {
    if valid {
        (&*ptr).row_count(Some(item)) as c_int
    } else {
        (&*ptr).row_count(None) as c_int
    }
}
#[no_mangle]
pub unsafe extern "C" fn persons_can_fetch_more(ptr: *const Persons, item: usize, valid: bool) -> bool {
    if valid {
        (&*ptr).can_fetch_more(Some(item))
    } else {
        (&*ptr).can_fetch_more(None)
    }
}
#[no_mangle]
pub unsafe extern "C" fn persons_fetch_more(ptr: *mut Persons, item: usize, valid: bool) {
    if valid {
        (&mut *ptr).fetch_more(Some(item))
    } else {
        (&mut *ptr).fetch_more(None)
    }
}
#[no_mangle]
pub unsafe extern "C" fn persons_sort(ptr: *mut Persons, column: u8, order: SortOrder) {
    (&mut *ptr).sort(column, order)
}
#[no_mangle]
pub unsafe extern "C" fn persons_index(ptr: *const Persons, item: usize, valid: bool, row: c_int) -> usize {
    if !valid {
        (&*ptr).index(None, row as usize)
    } else {
        (&*ptr).index(Some(item), row as usize)
    }
}
#[no_mangle]
pub unsafe extern "C" fn persons_parent(ptr: *const Persons, index: usize) -> QModelIndex {
    if let Some(parent) = (&*ptr).parent(index) {
        QModelIndex::create((&*ptr).row(parent) as c_int, parent)
    } else {
        QModelIndex::invalid()
    }
}
#[no_mangle]
pub unsafe extern "C" fn persons_row(ptr: *const Persons, item: usize) -> c_int {
    (&*ptr).row(item) as c_int
}

#[no_mangle]
pub unsafe extern "C" fn persons_data_user_name(ptr: *const Persons, item: usize,
        d: *mut c_void,
        set: fn(*mut c_void, QString)) {
    let data = (&*ptr).user_name(item);
    set(d, QString::from(&data));
}

#[no_mangle]
pub unsafe extern "C" fn persons_set_data_user_name(ptr: *mut Persons, item: usize, v: QStringIn) -> bool {
    (&mut *ptr).set_user_name(item, v.convert())
}
