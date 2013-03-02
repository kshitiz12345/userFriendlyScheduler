package com.service;

import java.util.List;

import com.dao.EmailDao;
import com.domain.CategoryDomain;
import com.domain.EmailDomain;

public class EmailService {

	public void addEmails(List<EmailDomain> emailDomainList) throws Exception {

		try {
			for (EmailDomain emailDomain : emailDomainList) {
				if (checkEmail(emailDomain.getEmailId()))
					emailDomainList.remove(emailDomain);
				else
					emailDomain.setDelete('Y');
			}
			EmailDao emailDao = new EmailDao();
			emailDao.addEmails(emailDomainList);
		} catch (Exception exception) {
			throw exception;
		}
	}

	public List<EmailDomain> getEmailByCategories(
			List<CategoryDomain> categoryDomainList) throws Exception {
		try {
			EmailDao emailDao = new EmailDao();
			return emailDao.getEmailByCategories(categoryDomainList);
		} catch (Exception exception) {
			throw exception;
		}
	}

	public boolean checkEmail(String emailId) throws Exception {
		try {
			EmailDao emailDao = new EmailDao();
			return emailDao.checkEmail(emailId);
		} catch (Exception exception) {
			throw exception;
		}
	}
}
