package com.dao;

import java.util.ArrayList;
import java.util.List;

import org.hibernate.HibernateException;
import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.Transaction;

import com.domain.CategoryDomain;
import com.domain.EmailDomain;
import com.entity.CategoryEntity;
import com.entity.EmailEntity;

public class EmailDao {

	public EmailDomain getEmailDomain(EmailEntity emailEntity) {

		EmailDomain emailDomain = new EmailDomain();

		emailDomain.setEmailId(emailEntity.getEmailId());
		emailDomain.setNumber(emailEntity.getNumber());
		emailDomain.setNumber(emailEntity.getNumber());
		emailEntity.setDeleted(emailEntity.getDeleted());

		return emailDomain;
	}

	public EmailEntity getEmailEntity(EmailDomain emailDomain) {

		EmailEntity emailEntity = new EmailEntity();

		emailEntity.setEmailId(emailDomain.getEmailId());
		emailEntity.setDeleted(emailDomain.getDelete());
		emailEntity.setNumber(emailDomain.getNumber());

		List<CategoryDomain> categoryDomainList = emailDomain
				.getCategoryDomainList();
		List<CategoryEntity> categoryEntityList = new ArrayList<CategoryEntity>();
		for (CategoryDomain categoryDomain : categoryDomainList) {
			CategoryEntity categoryEntity = new CategoryEntity();
			categoryEntity.setCategoryId(categoryDomain.getCategoryId());
			categoryEntityList.add(categoryEntity);
		}
		emailEntity.setCategoryEntityList(categoryEntityList);

		return emailEntity;
	}

	public void addEmails(List<EmailDomain> emailDomainList) {
		Session session = HibernateUtil.getSessionFactory().getCurrentSession();
		Transaction transaction = null;
		try {
			transaction = session.beginTransaction();
			for (EmailDomain emailDomain : emailDomainList) {
				EmailEntity emailEntity = getEmailEntity(emailDomain);
				session.save(emailEntity);
				/*
				 * List<CategoryEntity> categoryEntityList = emailEntity
				 * .getCategoryEntityList(); for (CategoryEntity categoryEntity
				 * : categoryEntityList) { session.update(categoryEntity); }
				 */
			}
		} catch (HibernateException e) {
			if (transaction != null)
				transaction.rollback();
			e.printStackTrace();
		} finally {
			transaction.commit();
			// session.close();
		}

	}

	public void deleteEmails(List<EmailDomain> emailDomainList) {
		Session session = HibernateUtil.getSessionFactory().getCurrentSession();
		Transaction transaction = null;

		try {
			transaction = session.beginTransaction();
			for (EmailDomain emailDomain : emailDomainList) {
				EmailEntity emailEntity = getEmailEntity(emailDomain);
				session.delete(emailEntity);
			}
		} catch (HibernateException e) {
			if (transaction != null)
				transaction.rollback();
			e.printStackTrace();
		} finally {
			transaction.commit();
			// session.close();
		}
	}

	public List<EmailDomain> getEmailByCategories(
			List<CategoryDomain> categoryDomainList) {
		Session session = HibernateUtil.getSessionFactory().getCurrentSession();
		Transaction transaction = null;
		List<EmailDomain> emailDomainList = new ArrayList<EmailDomain>();
		try {
			transaction = session.beginTransaction();
			String hql = new String();
			for (CategoryDomain categoryDomain : categoryDomainList) {
				hql = "select e from " + CategoryEntity.class.getName() + " c "
						+ "join c.emailEntityList e "
						+ "where c.categoryId = :categoryId";
				Query query = session.createQuery(hql);
				query.setParameter("categoryId", categoryDomain.getCategoryId());
				@SuppressWarnings("unchecked")
				List<EmailEntity> emailEntityList = query.list();
				for (EmailEntity emailEntity : emailEntityList) {
					if (emailEntity.getDeleted() != 'Y')
						emailDomainList.add(getEmailDomain(emailEntity));
				}

			}
			return emailDomainList;
		} catch (HibernateException e) {
			if (transaction != null)
				transaction.rollback();
			e.printStackTrace();
		} finally {
			transaction.commit();
			// session.close();
		}
		return emailDomainList;

	}

	public boolean checkEmail(String emailId) throws Exception {

		Session session = HibernateUtil.getSessionFactory().getCurrentSession();
		Transaction transaction = null;
		try {
			transaction = session.beginTransaction();
			@SuppressWarnings("unchecked")
			List<EmailEntity> emailEntityList = (List<EmailEntity>) session
					.createQuery(
							"select e from " + EmailEntity.class.getName()
									+ " e where e.emailId=?")
					.setParameter(0, emailId).list();
			if (emailEntityList.size() == 0)
				return false;
			else
				return true;
		} catch (HibernateException e) {
			if (transaction != null)
				transaction.rollback();
			e.printStackTrace();
		} catch (Exception exception) {
			throw exception;
		} finally {
			// session.close();
			transaction.commit();
		}
		return false;
	}

}
