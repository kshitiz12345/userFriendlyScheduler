package com.dao;

import java.util.ArrayList;
import java.util.List;

import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.Transaction;

import com.domain.CategoryDomain;
import com.entity.CategoryEntity;

public class CategoryDao {

	public CategoryEntity getCategoryEntity(CategoryDomain categoryDomain) {

		CategoryEntity categoryEntity = new CategoryEntity();

		categoryEntity.setCategory(categoryDomain.getCategory());
		categoryEntity.setCategoryId(categoryDomain.getCategoryId());
		return categoryEntity;
	}

	public CategoryDomain getCategoryDomain(CategoryEntity categoryEntity) {

		CategoryDomain categoryDomain = new CategoryDomain();

		categoryDomain.setCategory(categoryEntity.getCategory());
		categoryDomain.setCategoryId(categoryEntity.getCategoryId());
		return categoryDomain;
	}

	public List<CategoryDomain> getAllCategories() throws Exception {

		Session session = HibernateUtil.getSessionFactory().getCurrentSession();
		Transaction transaction = null;
		List<CategoryDomain> categoryDomainList = new ArrayList<CategoryDomain>();
		try {
			transaction = session.beginTransaction();
			@SuppressWarnings("unchecked")
			List<CategoryEntity> categoryEntityList = session.createQuery(
					"select c from " + CategoryEntity.class.getName() + " c")
					.list();
			for (CategoryEntity categoryEntity : categoryEntityList) {
				categoryDomainList.add(getCategoryDomain(categoryEntity));
			}
			return categoryDomainList;
		} catch (HibernateException e) {
			if (transaction != null)
				transaction.rollback();
			throw e;
		} catch (Exception exception) {
			throw exception;
		} finally {
			transaction.commit();
			// session.close();
		}
	}

}
