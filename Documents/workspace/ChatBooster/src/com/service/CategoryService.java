package com.service;

import java.util.List;

import com.dao.CategoryDao;
import com.domain.CategoryDomain;

public class CategoryService {
	
	public List<CategoryDomain> getAllCategories() throws Exception {

		CategoryDao categoryDao = new CategoryDao();
		try {
			return categoryDao.getAllCategories();
		} catch (Exception exception) {
			throw exception;
		}
	}


}
